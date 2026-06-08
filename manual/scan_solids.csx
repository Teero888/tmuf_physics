#r "nuget: GBX.NET, *"
#r "nuget: GBX.NET.LZO, *"
using GBX.NET;
using GBX.NET.LZO;
using GBX.NET.Engines.Plug;
using System.IO;

Gbx.LZO = new Lzo();
var dir = "../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid";
var types = new System.Collections.Generic.Dictionary<string, int>();

var file = "../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/7220FB270B29D1DAD35DAB8255815743FB";
try {
    var node = Gbx.ParseNode(file);
    System.Console.WriteLine($"Parsed as {node?.GetType().Name}");
} catch (System.Exception ex) {
    System.Console.WriteLine($"Exception for {file}: {ex}");
}
