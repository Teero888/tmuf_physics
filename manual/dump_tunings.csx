#r "nuget: GBX.NET, *"
#r "nuget: GBX.NET.LZO, *"
using System;
using GBX.NET;
using GBX.NET.LZO;
using System.Collections;
using GBX.NET.Engines.Game;

Gbx.LZO = new Lzo();
var gbx = Gbx.ParseNode("../StadiumCar.VehicleTunings.Gbx");

var props = gbx.GetType().GetProperties();
foreach (var p in props) {
    try {
        var val = p.GetValue(gbx);
        Console.WriteLine($"  {p.Name} = {val}");
        if (val != null && val.GetType().Name == "CFuncKeysReal") {
            var cprops = val.GetType().GetProperties();
            foreach (var cp in cprops) {
                try {
                    var cval = cp.GetValue(val);
                    if (cval is IEnumerable ienum && !(cval is string)) {
                        Console.WriteLine($"      {cp.Name}:");
                        foreach(var item in ienum) {
                            Console.WriteLine($"        {item}");
                        }
                    } else {
                        Console.WriteLine($"      {cp.Name} = {cval}");
                    }
                } catch {}
            }
        }
    } catch {}
}
