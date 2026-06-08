#r "nuget: GBX.NET, *"
#r "nuget: GBX.NET.LZO, *"
using GBX.NET;
using GBX.NET.LZO;
using GBX.NET.Engines.Plug;
using GBX.NET.Engines.Game;
using GBX.NET.Engines.Hms;
using System.IO;
using System.Linq;

Gbx.LZO = new Lzo();
var path = "../steamdata/GameData/Stadium_Extracted/Stadium/ConstructionBlockInfo/ConstructionBlockInfoClassic/StadiumCircuitBase.TMEDClassic.Gbx";
try {
    var node = Gbx.ParseNode(path);
    if (node is CGameCtnBlockInfoClassic binfo) {
        if (binfo.GroundMobils != null) {
            foreach (var arr in binfo.GroundMobils) {
                foreach (var ext in arr) {
                    var m = ext.Node;
                    if (m != null) {
                        System.Console.WriteLine($"Mobil: {m.GetType().Name}");
                        foreach (var p in m.GetType().GetProperties()) {
                            try {
                                var val = p.GetValue(m);
                                System.Console.WriteLine($"  {p.Name}: {(val == null ? "null" : val.GetType().Name)}");
                                if (p.Name == "Item" && val is CHmsItem item) {
                                    System.Console.WriteLine($"    Item: CHmsItem");
                                    var solid = item.Solid;
                                    if (solid != null) {
                                        System.Console.WriteLine($"      Solid: {solid.GetType().Name}");
                                        foreach(var sp in solid.GetType().GetProperties()) {
                                            try {
                                                var sval = sp.GetValue(solid);
                                                System.Console.WriteLine($"        {sp.Name}: {sval?.GetType().Name ?? "null"}");
                                                if (sp.Name == "TreeFile" && sval != null) {
                                                    dynamic rtf = sval;
                                                    System.Console.WriteLine($"          FilePath: {rtf.FilePath}");
                                                }
                                            } catch { }
                                        }
                                    }
                                }
                            } catch { }
                        }
                    }
                }
            }
        }
    }
} catch (System.Exception ex) {
    System.Console.WriteLine($"Error: {ex.Message}");
}
