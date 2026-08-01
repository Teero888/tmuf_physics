#r "nuget: GBX.NET, *"
#r "nuget: GBX.NET.LZO, *"
#r "nuget: GBX.NET.ZLib, *"
using GBX.NET;
using GBX.NET.LZO;
using GBX.NET.ZLib;
using GBX.NET.Engines.Game;
using System.IO;
using System.Linq;

Gbx.LZO = new Lzo();
Gbx.ZLib = new ZLib();
var gbx = Gbx.ParseNode("../steamdata/GameData/Stadium_Extracted/Vehicles/TrackManiaVehicle/StadiumCar.ConstructionVehicle.Gbx");

System.Console.WriteLine($"Node type: {gbx.GetType().Name}");
var props = gbx.GetType().GetProperties();
foreach (var p in props) {
    try {
        var val = p.GetValue(gbx);
        System.Console.WriteLine($"  {p.Name} = {val}");
    } catch {}
}

