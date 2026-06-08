#r "nuget: GBX.NET, *"
#r "nuget: GBX.NET.LZO, *"
using GBX.NET;
using GBX.NET.LZO;
Gbx.LZO = new Lzo();
var path = "../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B";
try {
    var node = Gbx.ParseNode(path);
    System.Console.WriteLine($"Parsed as {node?.GetType().Name}");
    if (node is GBX.NET.Engines.Plug.CPlugSolid solid) {
        var tree = solid.Tree;
        System.Console.WriteLine($"Tree: {(tree != null ? tree.GetType().Name : "null")}");
        if (tree != null) {
            foreach (var v in tree.Visuals) {
                System.Console.WriteLine($"Visual: {v.GetType().Name}");
                if (v is GBX.NET.Engines.Plug.CPlugVisual3D v3d) {
                    System.Console.WriteLine($"  Vertices: {v3d.Vertices?.Count ?? 0}");
                }
            }
        }
    }
} catch (System.Exception ex) {
    System.Console.WriteLine($"Error: {ex.Message}");
}
