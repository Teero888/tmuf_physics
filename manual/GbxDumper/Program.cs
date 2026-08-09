using System;
using System.IO;
using GBX.NET;
using GBX.NET.LZO;
using GBX.NET.Engines.Plug;
using System.Reflection;
using System.Collections;

class Program {
    static void PrintObject(object obj, string indent) {
        if (obj == null) return;
        var props = obj.GetType().GetProperties();
        foreach (var p in props) {
            try {
                var val = p.GetValue(obj);
                if (val != null && val.GetType().Name == "CFuncKeysReal") {
                    Console.WriteLine($"{indent}{p.Name}:");
                    var cprops = val.GetType().GetProperties();
                    foreach (var cp in cprops) {
                        try {
                            var cval = cp.GetValue(val);
                            if (cval is IEnumerable ienum && !(cval is string)) {
                                Console.WriteLine($"{indent}  {cp.Name}:");
                                foreach(var item in ienum) {
                                    Console.WriteLine($"{indent}    {item}");
                                }
                            } else {
                                Console.WriteLine($"{indent}  {cp.Name} = {cval}");
                            }
                        } catch {}
                    }
                } else if (val is IEnumerable ien && !(val is string)) {
                    if (p.Name == "Tuning") {
                        // skip
                    } else {
                        Console.WriteLine($"{indent}{p.Name}:");
                        var index = 0;
                        foreach (var item in ien) {
                            Console.WriteLine($"{indent}  [{index++}] = {item}");
                        }
                    }
                } else {
                    Console.WriteLine($"{indent}{p.Name} = {val}");
                }
            } catch {}
        }
    }

    static void Main(string[] args) {
        Gbx.LZO = new Lzo();
        var gbx = Gbx.ParseNode("../../StadiumCar.VehicleTunings.Gbx");
        var tuningsProp = gbx.GetType().GetProperty("Tuning");
        if (tuningsProp != null) {
            var tuningsArr = tuningsProp.GetValue(gbx) as Array;
            if (tuningsArr != null && tuningsArr.Length > 29) {
                Console.WriteLine("--- TUNING [29] ---");
                PrintObject(tuningsArr.GetValue(29), "");
            }
        }
    }
}
