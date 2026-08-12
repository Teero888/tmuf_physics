using System.Runtime.CompilerServices;
using System.Text;
using GBX.NET;
using GBX.NET.Engines.Game;
using GBX.NET.Engines.Plug;
using GBX.NET.Engines.Scene;
using GBX.NET.LZO;
using GBX.NET.PAK;

if (args.Length >= 1 && args[0] == "--vehicle")
{
    if (args.Length != 4)
    {
        Console.Error.WriteLine(
            "Usage: TrackCollisionExtractor --vehicle <Packs directory> " +
            "<collision.tmnfveh> <visual.obj>");
        return 2;
    }
    return await ExtractStadiumVehicleAsync(
        Path.GetFullPath(args[1]),
        Path.GetFullPath(args[2]),
        Path.GetFullPath(args[3]));
}

if (args.Length < 3)
{
    Console.Error.WriteLine(
        "Usage: TrackCollisionExtractor <map.Challenge.Gbx> <Packs directory> " +
        "<output.tmnfcol> [--indices=42,43]");
    return 2;
}

var mapPath = Path.GetFullPath(args[0]);
var packsPath = Path.GetFullPath(args[1]);
var outputPath = Path.GetFullPath(args[2]);
var selectedIndices = ParseSelectedIndices(args.Skip(3));
var decorationVisualPath = ParseOption(args.Skip(3), "--decoration-visual=");

Gbx.LZO = new Lzo();
var challenge = Gbx.ParseNode(mapPath) as CGameCtnChallenge
    ?? throw new InvalidDataException($"{mapPath} is not a CGameCtnChallenge");
var challengeBlocks = challenge.Blocks
    ?? throw new InvalidDataException($"{mapPath} has no block list");

var pakList = await PakList.ParseAsync(Path.Combine(packsPath, "packlist.dat"), PakListGame.TM);
var keys = pakList.ToKeyInfoDictionary();
await using var stadiumPak = await Pak.ParseAsync(
    Path.Combine(packsPath, "Stadium.pak"), keys["Stadium"]);

var extractor = new CollisionExtractor(stadiumPak);
var output = new CollisionMesh();
var unresolvedBlocks = new SortedSet<string>(StringComparer.Ordinal);
var exportedBlocks = 0;

foreach (var (block, index) in challengeBlocks.Select((value, index) => (value, index)))
{
    if (selectedIndices is not null && !selectedIndices.Contains(index))
        continue;

    var localMeshes = await extractor.GetBlockMeshesAsync(block);
    if (localMeshes.Count == 0)
    {
        unresolvedBlocks.Add(block.Name);
        continue;
    }

    foreach (var mesh in localMeshes)
        output.AppendBlock(mesh.Mesh, block, mesh.BlockSize);
    exportedBlocks++;
}

var decorationSolid = await extractor.ResolveDecorationSolidAsync(
    challenge.Decoration.Id.ToString());
if (decorationSolid is not null)
{
    output.AppendLocal(await extractor.ExtractSolidCollisionAsync(decorationSolid));
    if (decorationVisualPath is not null)
    {
        var fullVisualPath = Path.GetFullPath(decorationVisualPath);
        Directory.CreateDirectory(Path.GetDirectoryName(fullVisualPath)!);
        decorationSolid.ExportToObj(
            fullVisualPath, Path.ChangeExtension(fullVisualPath, ".mtl"),
            mergeVerticesDigitThreshold: 5, lod: 1);
    }
}
else
{
    Console.Error.WriteLine(
        $"Could not resolve the {challenge.Decoration.Id} Stadium decoration solid");
}

Directory.CreateDirectory(Path.GetDirectoryName(outputPath)!);
output.Write(outputPath, exportedBlocks);

Console.WriteLine(
    $"Exported {exportedBlocks} blocks, {output.Vertices.Count} vertices, " +
    $"{output.Triangles.Count} triangles to {outputPath}");
if (unresolvedBlocks.Count != 0)
{
    Console.WriteLine($"No collision mobil resolved for {unresolvedBlocks.Count} block models:");
    foreach (var name in unresolvedBlocks)
        Console.WriteLine($"  {name}");
}

return 0;

static async Task<int> ExtractStadiumVehicleAsync(
    string packsPath, string collisionPath, string visualPath)
{
    Gbx.LZO = new Lzo();
    var pakList = await PakList.ParseAsync(
        Path.Combine(packsPath, "packlist.dat"), PakListGame.TM);
    var keys = pakList.ToKeyInfoDictionary();
    await using var stadiumPak = await Pak.ParseAsync(
        Path.Combine(packsPath, "Stadium.pak"), keys["Stadium"]);
    var extractor = new CollisionExtractor(stadiumPak);
    // CGameItemModel's VehicleFile points to StadiumCar.Car.Vehicle.Gbx. Its
    // native reference table selects this exact CPlugSolid for both the HMS
    // item and the visible car; reading the solid directly avoids an old
    // CHmsSoundSource chunk that GBX.NET cannot decode.
    var vehicleSolid = await extractor.OpenNodeByLogicalPathAsync<CPlugSolid>(
        "Media/Solid/StadiumCar.Solid.Gbx");
    if (vehicleSolid is null)
    {
        Console.Error.WriteLine("Could not resolve Media/Solid/StadiumCar.Solid.Gbx");
        return 1;
    }

    var collision = await extractor.ExtractVehiclePrimitivesAsync(vehicleSolid);
    if (collision.Primitives.Count == 0)
    {
        Console.Error.WriteLine("The Stadium car solid contains no collision primitives");
        return 1;
    }
    Directory.CreateDirectory(Path.GetDirectoryName(collisionPath)!);
    collision.Write(collisionPath);

    Directory.CreateDirectory(Path.GetDirectoryName(visualPath)!);
    vehicleSolid.ExportToObj(
        visualPath, Path.ChangeExtension(visualPath, ".mtl"),
        mergeVerticesDigitThreshold: 6, lod: 0);
    Console.WriteLine(
        $"Exported Stadium car collision ({collision.Primitives.Count} primitives) " +
        $"and visual model to {visualPath}");
    return 0;
}

static HashSet<int>? ParseSelectedIndices(IEnumerable<string> options)
{
    const string prefix = "--indices=";
    var option = options.SingleOrDefault(x => x.StartsWith(prefix, StringComparison.Ordinal));
    if (option is null)
        return null;
    return option[prefix.Length..]
        .Split(',', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries)
        .Select(int.Parse)
        .ToHashSet();
}

static string? ParseOption(IEnumerable<string> options, string prefix) =>
    options.SingleOrDefault(x => x.StartsWith(prefix, StringComparison.Ordinal))
        ?[prefix.Length..];

internal sealed class CollisionExtractor
{
    private readonly Pak pak;
    private readonly Dictionary<string, PakFile?> resolvedFiles =
        new(StringComparer.OrdinalIgnoreCase);
    private readonly Dictionary<string, Task<LocalCollisionMesh?>> solidMeshes =
        new(StringComparer.OrdinalIgnoreCase);
    private readonly Dictionary<string, Task<ushort>> materialIds =
        new(StringComparer.OrdinalIgnoreCase);
    private readonly Dictionary<string, PakFile> blockInfos;

    public CollisionExtractor(Pak pak)
    {
        this.pak = pak;
        blockInfos = pak.Files.Values
            .Where(file => file.Name.Contains("ConstructionBlockInfo", StringComparison.OrdinalIgnoreCase) &&
                           file.Name.EndsWith(".Gbx", StringComparison.OrdinalIgnoreCase))
            .Select(file => (File: file, Name: GetBlockInfoName(file.Name)))
            .Where(pair => pair.Name is not null)
            .GroupBy(pair => pair.Name!, StringComparer.OrdinalIgnoreCase)
            .ToDictionary(group => group.Key, group => group.First().File,
                          StringComparer.OrdinalIgnoreCase);
    }

    public async Task<IReadOnlyList<ResolvedBlockCollision>> GetBlockMeshesAsync(
        CGameCtnBlock block)
    {
        var blockInfoFile = ResolveBlockInfo(block.Name);
        if (blockInfoFile is null)
            return Array.Empty<ResolvedBlockCollision>();

        Gbx gbx;
        try
        {
            gbx = await pak.OpenGbxFileAsync(blockInfoFile);
        }
        catch (Exception exception)
        {
            Console.Error.WriteLine($"Could not parse block info {block.Name}: {exception.Message}");
            return Array.Empty<ResolvedBlockCollision>();
        }

        if (gbx.Node is not CGameCtnBlockInfo info)
            return Array.Empty<ResolvedBlockCollision>();

        var meshes = new List<LocalCollisionMesh>();
        var mobilGroups = block.IsGround ? info.GroundMobils : info.AirMobils;
        if (mobilGroups is not null && mobilGroups.Length != 0)
        {
            var groupIndex = Math.Min(block.Variant, (byte)(mobilGroups.Length - 1));
            foreach (var mobilRef in mobilGroups[groupIndex])
            {
                var mobil = mobilRef.Node;
                if (mobil is null && mobilRef.File?.FilePath is { Length: > 0 } mobilPath)
                    mobil = await OpenNodeAsync<CSceneMobil>(mobilPath);
                if (mobil is not null)
                    await AddMobilMeshesAsync(mobil, meshes);
            }
        }

        var variant = SelectVariant(info, block);
        if (variant?.Mobils is not null)
        {
            foreach (var group in variant.Mobils)
            foreach (var mobilInfo in group)
            {
                if (mobilInfo.SolidFid is not null)
                    meshes.Add(await ExtractSolidAsync(mobilInfo.SolidFid));
                else if (mobilInfo.SolidFidFile?.FilePath is { Length: > 0 } solidPath)
                    await AddExternalSolidAsync(solidPath, meshes);
                if (mobilInfo.OldMobil is not null)
                    await AddMobilMeshesAsync(mobilInfo.OldMobil, meshes);
            }
        }

        var blockSize = GetBlockSize(info, block.IsGround);
        return meshes
            .Where(mesh => mesh.Triangles.Count != 0)
            .Select(mesh => new ResolvedBlockCollision(mesh, blockSize))
            .ToArray();
    }

    public Task<T?> OpenNodeByLogicalPathAsync<T>(
        string logicalPath, bool tolerateBodyErrors = false)
        where T : class => OpenNodeAsync<T>(logicalPath, tolerateBodyErrors);

    public async Task<Gbx?> OpenGbxByLogicalPathAsync(
        string logicalPath, bool tolerateBodyErrors = false)
    {
        var file = ResolveFile(logicalPath);
        if (file is null)
            return null;
        var settings = tolerateBodyErrors
            ? new GbxReadSettings { IgnoreExceptionsInBody = true }
            : default;
        return await pak.OpenGbxFileAsync(file, settings);
    }

    public Task<LocalCollisionMesh> ExtractSolidCollisionAsync(CPlugSolid solid) =>
        ExtractSolidAsync(solid);

    public async Task<CPlugSolid?> ResolveDecorationSolidAsync(string mood)
    {
        var decorationFile = pak.Files.Values.FirstOrDefault(file =>
            file.Name.Contains("ConstructionDecoration",
                               StringComparison.OrdinalIgnoreCase) &&
            file.Name.EndsWith(mood + ".TMDecoration.Gbx",
                               StringComparison.OrdinalIgnoreCase));
        if (decorationFile is null)
            return null;
        CGameCtnDecoration? decoration;
        try
        {
            decoration = (await pak.OpenGbxFileAsync(decorationFile)).Node
                as CGameCtnDecoration;
        }
        catch (Exception exception)
        {
            Console.Error.WriteLine(
                $"Could not parse decoration {mood}: {exception.Message}");
            return null;
        }
        var scenePath = decoration?.DecoSize?.SceneFile?.FilePath;
        if (string.IsNullOrEmpty(scenePath))
            return null;
        var scene = await OpenGbxByLogicalPathAsync(scenePath,
                                                    tolerateBodyErrors: true);
        var solidPath = scene?.RefTable?.Files
            .Select(file => file.FilePath.Replace('\\', '/'))
            .FirstOrDefault(path =>
                path.Contains("/Media/Solid/Zone/",
                              StringComparison.OrdinalIgnoreCase) &&
                path.EndsWith(".Solid.Gbx",
                              StringComparison.OrdinalIgnoreCase));
        return solidPath is null
            ? null
            : await OpenNodeAsync<CPlugSolid>(solidPath);
    }

    public async Task<LocalCollisionMesh> ExtractSolidResourceCollisionAsync(
        CPlugSolid solid)
    {
        if (solid.Tree is null &&
            solid.TreeFile?.FilePath is { Length: > 0 } treePath)
        {
            solid.Tree = await OpenNodeAsync<CPlugTree>(treePath);
        }
        return await ExtractSolidAsync(solid);
    }

    public async Task<VehicleCollisionAsset> ExtractVehiclePrimitivesAsync(
        CPlugSolid solid)
    {
        if (solid.Tree is null &&
            solid.TreeFile?.FilePath is { Length: > 0 } treePath)
        {
            solid.Tree = await OpenNodeAsync<CPlugTree>(treePath);
        }
        var output = new VehicleCollisionAsset();
        if (solid.Tree is CPlugTree tree)
            await ExtractVehicleTreeAsync(tree, Transform.Identity, output,
                                          new HashSet<int>());
        return output;
    }

    private async Task ExtractVehicleTreeAsync(
        CPlugTree tree,
        Transform parentTransform,
        VehicleCollisionAsset output,
        HashSet<int> visitedTrees)
    {
        if (!visitedTrees.Add(RuntimeHelpers.GetHashCode(tree)))
            return;
        var transform = tree.Location is { } location
            ? parentTransform.Compose(Transform.FromIso4(location))
            : parentTransform;
        if (tree.IsCollidable && tree.Surface is CPlugSurface surface &&
            (surface.Surf ?? surface.Geom?.Surf) is
                CPlugSurface.Ellipsoid ellipsoid)
        {
            var surfaceIndex = ellipsoid.SurfaceIndex;
            var material = surfaceIndex >= 0 && surfaceIndex < surface.Materials.Length
                ? await ResolveMaterialIdAsync(surface.Materials[surfaceIndex])
                : ushort.MaxValue;
            output.Primitives.Add(new VehicleCollisionPrimitive(
                (Vec3)ellipsoid.Size, transform, material,
                GetVehiclePrimitiveRole(tree.Name)));
        }
        foreach (var child in tree.Children)
            await ExtractVehicleTreeAsync(
                child, transform, output, visitedTrees);
    }

    private static ushort GetVehiclePrimitiveRole(string name) => name switch
    {
        "FLSurf" => 1,
        "FRSurf" => 2,
        "RLSurf" => 3,
        "RRSurf" => 4,
        _ => 0
    };

    private static Int3 GetBlockSize(CGameCtnBlockInfo info, bool isGround)
    {
        // CGameCtnBlock::GetMobilLoc (TmForeverFixed.exe 0x0060ACB0 and
        // wrapper 0x0060B320) rotates around the block-info footprint at
        // native +0x58 for ground blocks or +0x64 for air blocks. Those
        // GmNat3 values are built from the unit-info RelativeOffset values.
        // A fixed one-cell pivot moves every rotated multi-cell block by one
        // or more complete 32 m tiles.
        var size = new Int3(1, 1, 1);
        foreach (var unit in isGround
                     ? info.GroundBlockUnitInfos ?? Array.Empty<CGameCtnBlockUnitInfo>()
                     : info.AirBlockUnitInfos ?? Array.Empty<CGameCtnBlockUnitInfo>())
        {
            size = new Int3(
                Math.Max(size.X, unit.RelativeOffset.X + 1),
                Math.Max(size.Y, unit.RelativeOffset.Y + 1),
                Math.Max(size.Z, unit.RelativeOffset.Z + 1));
        }
        return size;
    }

    private PakFile? ResolveBlockInfo(string name)
    {
        if (blockInfos.TryGetValue(name, out var exact))
            return exact;

        // TMNF stores the start/finish model under the base block-info name;
        // the challenge appends "Line" to the placed waypoint block.
        if (name.EndsWith("Line", StringComparison.OrdinalIgnoreCase) &&
            blockInfos.TryGetValue(name[..^4], out var withoutLine))
            return withoutLine;

        return null;
    }

    private static CGameCtnBlockInfoVariant? SelectVariant(
        CGameCtnBlockInfo info, CGameCtnBlock block)
    {
        if (block.IsGround)
        {
            if (block.Variant == 0)
                return info.VariantBaseGround;
            var variants = info.AdditionalVariantsGround;
            return variants is not null && block.Variant - 1 < variants.Length
                ? variants[block.Variant - 1]
                : null;
        }

        if (block.Variant == 0)
            return info.VariantBaseAir;
        var airVariants = info.AdditionalVariantsAir;
        return airVariants is not null && block.Variant - 1 < airVariants.Length
            ? airVariants[block.Variant - 1]
            : null;
    }

    private async Task AddMobilMeshesAsync(
        CSceneMobil mobil, ICollection<LocalCollisionMesh> meshes)
    {
        var solid = mobil.Item?.Solid;
        if (solid is not null)
        {
            if (solid.Tree is not null)
                meshes.Add(await ExtractSolidAsync(solid));
            else if (solid.TreeFile?.FilePath is { Length: > 0 } solidPath)
                await AddExternalSolidAsync(solidPath, meshes);
        }

        foreach (var link in mobil.ObjectLink ?? Array.Empty<CSceneObjectLink>())
        {
            if (link.Mobil is not null)
                await AddMobilMeshesAsync(link.Mobil, meshes);
            else if (link.MobilFile?.FilePath is { Length: > 0 } linkedMobilPath)
            {
                // Race trigger mobils carry gameplay volumes rather than a
                // static CPlugSurface and GBX.NET intentionally cannot decode
                // their old CHmsItem chunk. They do not belong in this cache.
                if (linkedMobilPath.Contains("Trigger", StringComparison.OrdinalIgnoreCase))
                    continue;
                var linkedMobil = await OpenNodeAsync<CSceneMobil>(linkedMobilPath);
                if (linkedMobil is not null)
                    await AddMobilMeshesAsync(linkedMobil, meshes);
            }
        }
    }

    private async Task AddExternalSolidAsync(
        string logicalPath, ICollection<LocalCollisionMesh> meshes)
    {
        if (!solidMeshes.TryGetValue(logicalPath, out var meshTask))
        {
            meshTask = LoadSolidMeshAsync(logicalPath);
            solidMeshes.Add(logicalPath, meshTask);
        }
        var mesh = await meshTask;
        if (mesh is not null)
            meshes.Add(mesh);
    }

    private async Task<LocalCollisionMesh?> LoadSolidMeshAsync(string logicalPath)
    {
        var solid = await OpenNodeAsync<CPlugSolid>(logicalPath);
        if (solid is null)
        {
            Console.Error.WriteLine($"Could not resolve solid {logicalPath}");
            return null;
        }
        return await ExtractSolidAsync(solid);
    }

    private async Task<T?> OpenNodeAsync<T>(
        string logicalPath, bool tolerateBodyErrors = false) where T : class
    {
        var file = ResolveFile(logicalPath);
        if (file is null)
            return null;
        try
        {
            var settings = tolerateBodyErrors
                ? new GbxReadSettings { IgnoreExceptionsInBody = true }
                : default;
            return (await pak.OpenGbxFileAsync(file, settings)).Node as T;
        }
        catch (Exception exception)
        {
            Console.Error.WriteLine($"Could not parse {logicalPath}: {exception.Message}");
            return null;
        }
    }

    private PakFile? ResolveFile(string logicalPath)
    {
        if (resolvedFiles.TryGetValue(logicalPath, out var cached))
            return cached;

        var normalized = logicalPath.Replace('\\', '/').TrimStart('/');
        var named = pak.Files.FirstOrDefault(pair =>
            pair.Key.EndsWith(normalized, StringComparison.OrdinalIgnoreCase) ||
            pair.Value.Name.EndsWith(normalized, StringComparison.OrdinalIgnoreCase)).Value;
        if (named is not null)
        {
            resolvedFiles.Add(logicalPath, named);
            return named;
        }

        var parts = normalized.Split('/', StringSplitOptions.RemoveEmptyEntries);
        for (var firstPart = 0; firstPart < parts.Length; firstPart++)
        {
            var suffix = string.Join('\\', parts.Skip(firstPart));
            var hash = GBX.NET.Crypto.MD5.Compute136(suffix);
            var hashed = pak.Files.Values.FirstOrDefault(file =>
                file.Name.Equals(hash, StringComparison.OrdinalIgnoreCase));
            if (hashed is null)
                continue;
            resolvedFiles.Add(logicalPath, hashed);
            return hashed;
        }

        resolvedFiles.Add(logicalPath, null);
        return null;
    }

    private async Task<LocalCollisionMesh> ExtractSolidAsync(CPlugSolid solid)
    {
        var result = new LocalCollisionMesh();
        if (solid.Tree is CPlugTree tree)
            await ExtractTreeAsync(tree, Transform.Identity, result, new HashSet<int>());
        return result;
    }

    private async Task ExtractTreeAsync(
        CPlugTree tree,
        Transform parentTransform,
        LocalCollisionMesh output,
        HashSet<int> visitedTrees)
    {
        if (!visitedTrees.Add(RuntimeHelpers.GetHashCode(tree)))
            return;

        var transform = tree.Location is { } location
            ? parentTransform.Compose(Transform.FromIso4(location))
            : parentTransform;

        if (tree.IsCollidable)
        {
            switch (tree.Surface)
            {
                case CPlugSurface surface:
                    await AddSurfaceAsync(surface.Surf ?? surface.Geom?.Surf,
                                          surface.Materials, transform, output);
                    break;
                case CPlugSurfaceGeom geom:
                    await AddSurfaceAsync(geom.Surf, null, transform, output,
                                          geom.SurfaceId);
                    break;
            }
        }

        foreach (var child in tree.Children)
            await ExtractTreeAsync(child, transform, output, visitedTrees);
    }

    private async Task AddSurfaceAsync(
        CPlugSurface.ISurf? surf,
        CPlugSurface.SurfMaterial[]? materials,
        Transform transform,
        LocalCollisionMesh output,
        CPlugSurface.MaterialId? commonMaterial = null)
    {
        if (surf is not CPlugSurface.Mesh mesh || mesh.CookedTriangles is null)
            return;

        var materialMap = new ushort[materials?.Length ?? 0];
        for (var i = 0; i < materialMap.Length; i++)
            materialMap[i] = await ResolveMaterialIdAsync(materials![i]);

        var vertexBase = output.Vertices.Count;
        output.Vertices.AddRange(mesh.Vertices.Select(transform.Apply));
        foreach (var triangle in mesh.CookedTriangles)
        {
            if ((uint)triangle.Indices.X >= mesh.Vertices.Length ||
                (uint)triangle.Indices.Y >= mesh.Vertices.Length ||
                (uint)triangle.Indices.Z >= mesh.Vertices.Length)
                continue;
            var material = commonMaterial is not null
                ? (ushort)commonMaterial.Value
                : triangle.SurfaceIndex >= 0 && triangle.SurfaceIndex < materialMap.Length
                    ? materialMap[triangle.SurfaceIndex]
                    : ushort.MaxValue;
            if (material == (ushort)CPlugSurface.MaterialId.NotCollidable)
                continue;
            output.Triangles.Add(new LocalTriangle(
                vertexBase + triangle.Indices.X,
                vertexBase + triangle.Indices.Y,
                vertexBase + triangle.Indices.Z,
                material));
        }
    }

    private Task<ushort> ResolveMaterialIdAsync(CPlugSurface.SurfMaterial material)
    {
        if (material.SurfaceId is not null)
            return Task.FromResult((ushort)material.SurfaceId.Value);
        if (material.Material is not null)
            return Task.FromResult((ushort)material.Material.SurfaceId);
        if (material.MaterialFile?.FilePath is not { Length: > 0 } materialPath)
            return Task.FromResult(ushort.MaxValue);
        if (!materialIds.TryGetValue(materialPath, out var task))
        {
            task = LoadMaterialIdAsync(materialPath);
            materialIds.Add(materialPath, task);
        }
        return task;
    }

    private async Task<ushort> LoadMaterialIdAsync(string materialPath)
    {
        var material = await OpenNodeAsync<CPlugMaterial>(materialPath);
        return material is null ? ushort.MaxValue : (ushort)material.SurfaceId;
    }

    private static string? GetBlockInfoName(string path)
    {
        var fileName = path.Replace('\\', '/').Split('/').Last();
        var marker = fileName.IndexOf(".TMED", StringComparison.OrdinalIgnoreCase);
        return marker > 0 ? fileName[..marker] : null;
    }
}

internal sealed class LocalCollisionMesh
{
    public List<Vec3> Vertices { get; } = new();
    public List<LocalTriangle> Triangles { get; } = new();
}

internal readonly record struct ResolvedBlockCollision(
    LocalCollisionMesh Mesh, Int3 BlockSize);
internal readonly record struct LocalTriangle(int A, int B, int C, ushort MaterialId);
internal readonly record struct WorldTriangle(
    uint A, uint B, uint C, Vec3 Normal, float PlaneDistance, ushort MaterialId);

internal readonly record struct VehicleCollisionPrimitive(
    Vec3 Radii, Transform Location, ushort MaterialId, ushort Role);

internal sealed class VehicleCollisionAsset
{
    public List<VehicleCollisionPrimitive> Primitives { get; } = new();

    public void Write(string path)
    {
        using var stream = File.Create(path);
        using var writer = new BinaryWriter(stream, Encoding.ASCII, leaveOpen: false);
        writer.Write(Encoding.ASCII.GetBytes("TMNFVEH1"));
        writer.Write((uint)Primitives.Count);
        writer.Write(0u);
        foreach (var primitive in Primitives)
        {
            writer.Write(1u); // Native GmSurf type: ellipsoid.
            writer.Write(primitive.MaterialId);
            writer.Write(primitive.Role);
            primitive.Radii.Write(writer);
            primitive.Location.Write(writer);
        }
    }
}

internal sealed class CollisionMesh
{
    public List<Vec3> Vertices { get; } = new();
    public List<WorldTriangle> Triangles { get; } = new();

    public void AppendLocal(LocalCollisionMesh localMesh)
    {
        var vertexBase = Vertices.Count;
        Vertices.AddRange(localMesh.Vertices);
        foreach (var triangle in localMesh.Triangles)
        {
            var a = (uint)(vertexBase + triangle.A);
            var b = (uint)(vertexBase + triangle.B);
            var c = (uint)(vertexBase + triangle.C);
            var normal = Vec3.Cross(Vertices[(int)b] - Vertices[(int)a],
                                    Vertices[(int)c] - Vertices[(int)a]).Normalized();
            if (normal.LengthSquared < 1e-12f)
                continue;
            Triangles.Add(new WorldTriangle(
                a, b, c, normal, -Vec3.Dot(normal, Vertices[(int)a]),
                triangle.MaterialId));
        }
    }

    public void AppendBlock(
        LocalCollisionMesh localMesh, CGameCtnBlock block, Int3 blockSize)
    {
        var vertexBase = Vertices.Count;
        Vertices.AddRange(localMesh.Vertices.Select(
            vertex => TransformBlock(vertex, block, blockSize)));
        foreach (var triangle in localMesh.Triangles)
        {
            var a = (uint)(vertexBase + triangle.A);
            var b = (uint)(vertexBase + triangle.B);
            var c = (uint)(vertexBase + triangle.C);
            var normal = Vec3.Cross(Vertices[(int)b] - Vertices[(int)a],
                                    Vertices[(int)c] - Vertices[(int)a]).Normalized();
            if (normal.LengthSquared < 1e-12f)
                continue;
            var planeDistance = -Vec3.Dot(normal, Vertices[(int)a]);
            Triangles.Add(new WorldTriangle(a, b, c, normal, planeDistance,
                                            triangle.MaterialId));
        }
    }

    public void Write(string path, int blockCount)
    {
        using var stream = File.Create(path);
        using var writer = new BinaryWriter(stream, Encoding.ASCII, leaveOpen: false);
        writer.Write(Encoding.ASCII.GetBytes("TMNFCOL1"));
        writer.Write((uint)Vertices.Count);
        writer.Write((uint)Triangles.Count);
        writer.Write((uint)blockCount);
        writer.Write(0u);
        foreach (var vertex in Vertices)
        {
            writer.Write(vertex.X);
            writer.Write(vertex.Y);
            writer.Write(vertex.Z);
        }
        foreach (var triangle in Triangles)
        {
            writer.Write(triangle.A);
            writer.Write(triangle.B);
            writer.Write(triangle.C);
            writer.Write(triangle.Normal.X);
            writer.Write(triangle.Normal.Y);
            writer.Write(triangle.Normal.Z);
            writer.Write(triangle.PlaneDistance);
            writer.Write(triangle.MaterialId);
            writer.Write((ushort)0);
        }
    }

    private static Vec3 TransformBlock(
        Vec3 vertex, CGameCtnBlock block, Int3 blockSize)
    {
        var baseX = block.Coord.X * 32.0f;
        var baseY = block.Coord.Y * 8.0f;
        var baseZ = block.Coord.Z * 32.0f;
        return block.Direction switch
        {
            Direction.North => new Vec3(baseX + vertex.X, baseY + vertex.Y,
                                        baseZ + vertex.Z),
            Direction.East => new Vec3(baseX + blockSize.Z * 32.0f - vertex.Z,
                                       baseY + vertex.Y,
                                       baseZ + vertex.X),
            Direction.South => new Vec3(baseX + blockSize.X * 32.0f - vertex.X,
                                        baseY + vertex.Y,
                                        baseZ + blockSize.Z * 32.0f - vertex.Z),
            Direction.West => new Vec3(baseX + vertex.Z, baseY + vertex.Y,
                                       baseZ + blockSize.X * 32.0f - vertex.X),
            _ => throw new InvalidDataException($"Unsupported block direction {block.Direction}")
        };
    }
}

internal readonly record struct Vec3(float X, float Y, float Z)
{
    public float LengthSquared => X * X + Y * Y + Z * Z;
    public Vec3 Normalized()
    {
        var length = MathF.Sqrt(LengthSquared);
        return length > 0.0f ? new Vec3(X / length, Y / length, Z / length) : this;
    }

    public static Vec3 operator -(Vec3 left, Vec3 right) =>
        new(left.X - right.X, left.Y - right.Y, left.Z - right.Z);
    public static float Dot(Vec3 left, Vec3 right) =>
        left.X * right.X + left.Y * right.Y + left.Z * right.Z;
    public static Vec3 Cross(Vec3 left, Vec3 right) =>
        new(left.Y * right.Z - left.Z * right.Y,
            left.Z * right.X - left.X * right.Z,
            left.X * right.Y - left.Y * right.X);

    public static implicit operator Vec3(GBX.NET.Vec3 value) =>
        new(value.X, value.Y, value.Z);

    public void Write(BinaryWriter writer)
    {
        writer.Write(X);
        writer.Write(Y);
        writer.Write(Z);
    }
}

internal readonly record struct Transform(
    float XX, float XY, float XZ,
    float YX, float YY, float YZ,
    float ZX, float ZY, float ZZ,
    float TX, float TY, float TZ)
{
    public static Transform Identity { get; } = new(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
        0, 0, 0);

    public static Transform FromIso4(Iso4 value) => new(
        value.XX, value.XY, value.XZ,
        value.YX, value.YY, value.YZ,
        value.ZX, value.ZY, value.ZZ,
        value.TX, value.TY, value.TZ);

    public Vec3 Apply(GBX.NET.Vec3 value) => Apply((Vec3)value);
    public Vec3 Apply(Vec3 value) => new(
        XX * value.X + XY * value.Y + XZ * value.Z + TX,
        YX * value.X + YY * value.Y + YZ * value.Z + TY,
        ZX * value.X + ZY * value.Y + ZZ * value.Z + TZ);

    public Transform Compose(Transform local) => new(
        XX * local.XX + XY * local.YX + XZ * local.ZX,
        XX * local.XY + XY * local.YY + XZ * local.ZY,
        XX * local.XZ + XY * local.YZ + XZ * local.ZZ,
        YX * local.XX + YY * local.YX + YZ * local.ZX,
        YX * local.XY + YY * local.YY + YZ * local.ZY,
        YX * local.XZ + YY * local.YZ + YZ * local.ZZ,
        ZX * local.XX + ZY * local.YX + ZZ * local.ZX,
        ZX * local.XY + ZY * local.YY + ZZ * local.ZY,
        ZX * local.XZ + ZY * local.YZ + ZZ * local.ZZ,
        XX * local.TX + XY * local.TY + XZ * local.TZ + TX,
        YX * local.TX + YY * local.TY + YZ * local.TZ + TY,
        ZX * local.TX + ZY * local.TY + ZZ * local.TZ + TZ);

    public void Write(BinaryWriter writer)
    {
        writer.Write(XX); writer.Write(XY); writer.Write(XZ);
        writer.Write(YX); writer.Write(YY); writer.Write(YZ);
        writer.Write(ZX); writer.Write(ZY); writer.Write(ZZ);
        writer.Write(TX); writer.Write(TY); writer.Write(TZ);
    }
}
