using System;
using System.Collections;
using System.Linq;
using GBX.NET;
using GBX.NET.LZO;
using GBX.NET.Engines.Plug;
using GBX.NET.Engines.Function;
using GBX.NET.Engines.MwFoundations;

// Prints every property of every tuning in a .VehicleTunings.Gbx, plus the
// chunk ids actually present.  The chunk ids matter: tools/tuning_chunk_offsets.py
// maps each id to the native member offsets it writes, so only fields whose
// chunk is present here have a value that came from the file rather than from
// CSceneVehicleCarTuning's constructor defaults.
class Program {
    static string Format(object value) {
        if (value == null) return "null";
        if (value is float f) return f.ToString("R", System.Globalization.CultureInfo.InvariantCulture) + "f";
        if (value != null && value.GetType().Name == "CFuncKeysReal") {
            dynamic curve = value;
            var xs = ((IEnumerable)curve.Xs)?.Cast<float>().ToArray();
            var ys = ((IEnumerable)curve.Ys)?.Cast<float>().ToArray();
            if (xs == null || ys == null) return "curve(empty)";
            object interp = null;
            try { interp = curve.RealInterp; } catch { }
            return "curve{ interp=" + (interp?.ToString() ?? "?")
                 + " x=[" + string.Join(", ", xs.Select(v => v.ToString("R", System.Globalization.CultureInfo.InvariantCulture)))
                 + "] y=[" + string.Join(", ", ys.Select(v => v.ToString("R", System.Globalization.CultureInfo.InvariantCulture))) + "] }";
        }
        if (value is float[] fa) return "[" + string.Join(", ", fa.Select(v => v.ToString("R", System.Globalization.CultureInfo.InvariantCulture))) + "]";
        if (value is int[] ia) return "[" + string.Join(", ", ia) + "]";
        if (value is Array arr && arr.Rank == 1) {
            var parts = new System.Collections.Generic.List<string>();
            foreach (var item in arr) parts.Add(item?.ToString() ?? "null");
            return "[" + string.Join(", ", parts) + "]";
        }
        return value.ToString();
    }

    static void Main(string[] args) {
        Gbx.LZO = new MiniLZO();
        var path = args.Length > 0 ? args[0] : "../../../StadiumCar.VehicleTunings.Gbx";
        var node = Gbx.ParseNode(path);
        if (node is not CPlugVehiclePhyTunings tunings) {
            Console.Error.WriteLine("not a CPlugVehiclePhyTunings: " + node?.GetType());
            return;
        }
        for (int i = 0; i < tunings.Tuning.Length; i++) {
            object tuning = tunings.Tuning[i];
            if (tuning == null) continue;
            Console.WriteLine("=== tuning[" + i + "] " + tuning.GetType().Name + " ===");
            Console.WriteLine("--- chunks present ---");
            foreach (var chunk in ((dynamic)tuning).Chunks) {
                Console.WriteLine("  0x" + chunk.Id.ToString("X8"));
            }
            Console.WriteLine("--- properties ---");
            foreach (var property in tuning.GetType().GetProperties().OrderBy(p => p.Name)) {
                object value;
                try { value = property.GetValue(tuning); } catch (Exception e) { value = "<" + e.GetType().Name + ">"; }
                Console.WriteLine("  " + property.Name + " = " + Format(value));
            }
        }
    }
}
