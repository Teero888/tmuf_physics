#r "nuget: GBX.NET, *"
#r "nuget: GBX.NET.LZO, *"
#r "nuget: GBX.NET.ZLib, *"
using GBX.NET;
using GBX.NET.LZO;
using GBX.NET.ZLib;
using GBX.NET.Engines.Game;
using System.IO;
using System.Linq;
using System.Reflection;

Gbx.LZO = new Lzo();
Gbx.ZLib = new ZLib();
var gbx = Gbx.ParseNode<CGameCtnReplayRecord>("../steamdata/GameData/Tracks/Campaigns/Nations/White/A01-Race.Replay.gbx");
var ghost = gbx.Ghosts.FirstOrDefault();
var samples = ghost.SampleData?.Samples;
var s0 = samples[0];
var sType = s0.GetType();

System.Console.WriteLine($"Sample type: {sType.FullName}");
System.Console.WriteLine("\nALL Properties:");
foreach (var prop in sType.GetProperties(BindingFlags.Public | BindingFlags.Instance | BindingFlags.NonPublic)) {
    try {
        var val = prop.GetValue(s0);
        System.Console.WriteLine($"  {prop.Name} ({prop.PropertyType.Name}): {val}");
    } catch (Exception ex) {
        System.Console.WriteLine($"  {prop.Name} ({prop.PropertyType.Name}): ERROR");
    }
}

System.Console.WriteLine("\nALL Fields:");
foreach (var field in sType.GetFields(BindingFlags.Public | BindingFlags.Instance | BindingFlags.NonPublic)) {
    try {
        var val = field.GetValue(s0);
        System.Console.WriteLine($"  {field.Name} ({field.FieldType.Name}): {val}");
    } catch (Exception ex) {
        System.Console.WriteLine($"  {field.Name} ({field.FieldType.Name}): ERROR");
    }
}

// Write CSV with position, speed, and whatever rotation/velocity is available
using (var writer = new StreamWriter("a01_ghost_full.csv")) {
    writer.WriteLine("time_ms,x,y,z,speed_kmh");
    foreach (var s in samples) {
        writer.WriteLine($"{(int)s.Time.TotalMilliseconds},{s.Position.X:F6},{s.Position.Y:F6},{s.Position.Z:F6},{s.VelocitySpeed:F4}");
    }
}

// Also write velocity as a separate CSV
try {
    using (var writer = new StreamWriter("a01_ghost_velocity.csv")) {
        writer.WriteLine("time_ms,vx,vy,vz");
        foreach (var s in samples) {
            writer.WriteLine($"{(int)s.Time.TotalMilliseconds},{s.Velocity.X:F6},{s.Velocity.Y:F6},{s.Velocity.Z:F6}");
        }
    }
    System.Console.WriteLine("\nVelocity CSV written!");
} catch (Exception ex) {
    System.Console.WriteLine($"\nCouldn't get velocity: {ex.Message}");
}

// Print first 3 with full detail
for (int i = 0; i < 3; i++) {
    var s = samples[i];
    System.Console.WriteLine($"\nt={s.Time.TotalSeconds:F2}s:");
    System.Console.WriteLine($"  Position: ({s.Position.X:F6}, {s.Position.Y:F6}, {s.Position.Z:F6})");
    try { System.Console.WriteLine($"  Velocity: ({s.Velocity.X:F6}, {s.Velocity.Y:F6}, {s.Velocity.Z:F6})"); } catch {}
    try { System.Console.WriteLine($"  Speed: {s.VelocitySpeed:F4} km/h"); } catch {}
    try { System.Console.WriteLine($"  Rotation: ({s.Rotation.X:F6}, {s.Rotation.Y:F6}, {s.Rotation.Z:F6}, {s.Rotation.W:F6})"); } catch {}
}
