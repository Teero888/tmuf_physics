using System;
using System.IO;
using GBX.NET;
using GBX.NET.LZO;
using GBX.NET.Engines.Plug;

class Program {
    static void Main(string[] args) {
        Gbx.LZO = new Lzo();
        var node = Gbx.ParseNode("../../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B");
        if (node is CPlugSolid solid) {
            Console.WriteLine("CPlugSolid parsed.");
            var tree = solid.Tree;
            if (tree != null) {
                foreach(var prop in tree.GetType().GetProperties()) {
                    Console.WriteLine($"{prop.Name}: {prop.PropertyType.Name}");
                    try {
                        var val = prop.GetValue(tree);
                        if (val is CPlugTreeVisualMip mip) {
                            foreach(var lvl in mip.Levels) {
                                Console.WriteLine($"Mip Level: {lvl.GetType().Name}");
                                foreach(var p2 in lvl.GetType().GetProperties()) {
                                    Console.WriteLine($"  {p2.Name}");
                                }
                            }
                        }
                    } catch {}
                }
            }
        }
    }
}
