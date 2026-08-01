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
var gbx = Gbx.ParseNode<CGameCtnReplayRecord>("../steamdata/GameData/Tracks/Campaigns/Nations/White/A01-Race.Replay.gbx");
var ghost = gbx.Ghosts.FirstOrDefault();
if (ghost == null) {
    System.Console.WriteLine("No ghosts found.");
    return;
}

System.Console.WriteLine($"Ghost RaceTime: {ghost.RaceTime}");

var samples = ghost.SampleData?.Samples;
if (samples == null || samples.Count == 0) {
    System.Console.WriteLine("No samples found in SampleData.");
    // Try to dump what we can about the ghost
    System.Console.WriteLine($"Ghost type: {ghost.GetType().Name}");
    var props = ghost.GetType().GetProperties();
    foreach (var p in props) {
        try {
            var val = p.GetValue(ghost);
            if (val != null)
                System.Console.WriteLine($"  {p.Name} = {val}");
        } catch {}
    }
    return;
}

System.Console.WriteLine($"Found {samples.Count} samples.");

// Write CSV for the testing framework
using (var writer = new StreamWriter("a01_ghost_samples.csv")) {
    writer.WriteLine("time_ms,x,y,z,speed_kmh");
    foreach (var s in samples) {
        writer.WriteLine($"{(int)s.Time.TotalMilliseconds},{s.Position.X:F6},{s.Position.Y:F6},{s.Position.Z:F6},{s.VelocitySpeed:F4}");
    }
}

// Also print first 50 and last 10 for debugging
System.Console.WriteLine("\nFirst 50 samples:");
for (int i = 0; i < Math.Min(50, samples.Count); i++) {
    var s = samples[i];
    System.Console.WriteLine($"t={s.Time.TotalSeconds:F2}s Pos=({s.Position.X:F4}, {s.Position.Y:F4}, {s.Position.Z:F4}) Spd={s.VelocitySpeed:F2}km/h");
}

System.Console.WriteLine($"\nLast 10 samples:");
for (int i = Math.Max(0, samples.Count - 10); i < samples.Count; i++) {
    var s = samples[i];
    System.Console.WriteLine($"t={s.Time.TotalSeconds:F2}s Pos=({s.Position.X:F4}, {s.Position.Y:F4}, {s.Position.Z:F4}) Spd={s.VelocitySpeed:F2}km/h");
}
