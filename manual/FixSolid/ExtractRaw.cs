using System;
using System.IO;
using System.IO.Compression;
using System.Linq;
using GBX.NET;
using GBX.NET.PAK;
using GBX.NET.Engines.Plug;
using System.Threading.Tasks;

class Program {
    static async Task Main(string[] args) {
        var pakPath = "../../steamdata/Packs/Stadium.pak";
        var pakData = File.ReadAllBytes(pakPath);
        var msInput = new MemoryStream(pakData);
        var key = "0FBEA15ACADFEE1638900A5683902A29";
        var pak = await Pak.ParseAsync(msInput, Convert.FromHexString(key).Select(x => (byte)(255 - x)).ToArray());
        
        var targetFile = pak.Files.Values.FirstOrDefault(f => f.Name.Contains("03087AFCAF9BD557046938047A36D3614B"));
        if (targetFile != null) {
            try {
                var gbx = await pak.OpenGbxFileAsync(targetFile);
                var solid = (CPlugSolid)gbx.Node;
                var tree = (CPlugTree)solid.Tree;
                var geom = (CPlugSurfaceGeom)tree.Visuals[0].Visual;
                var mesh = geom.Surf as CPlugSurface.Mesh;
                if (mesh != null) {
                    Console.WriteLine("First vertex: " + mesh.Vertices[0].X + ", " + mesh.Vertices[0].Y + ", " + mesh.Vertices[0].Z);
                }
            } catch (Exception e) {
                Console.WriteLine("Failed to parse: " + e.Message);
            }
        }
    }
}
