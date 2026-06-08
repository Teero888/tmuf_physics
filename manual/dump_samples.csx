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
var gbx = Gbx.ParseNode<CGameCtnReplayRecord>("../steamdata/GameData/Tracks/Campaigns/Nations/Black/E05-Endurance.Replay.Gbx");
var ghost = gbx.Ghosts.FirstOrDefault();
if (ghost == null) {
    System.Console.WriteLine("No ghosts found.");
    return;
}
var samples = ghost.SampleData?.Samples;
if (samples == null) {
    System.Console.WriteLine("No samples found.");
    return;
}
System.Console.WriteLine($"Found {samples.Count} samples.");
for (int i = 0; i < 400; i++) {
    var s = samples[i];
    System.Console.WriteLine($"t={s.Time.TotalSeconds:F2}s Pos=({s.Position.X:F4}, {s.Position.Y:F4}, {s.Position.Z:F4}) Spd={s.VelocitySpeed:F2}km/h");
}
