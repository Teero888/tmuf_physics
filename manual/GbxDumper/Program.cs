using System;
using System.IO;
using System.Linq;
using GBX.NET.PAK;

class Program {
    static void Main(string[] args) {
        using var fs = File.OpenRead("../../steamdata/Packs/Stadium.pak");
        var pak = Pak.Parse(fs);
        Console.WriteLine("Files count: " + pak.Files.Count);
    }
}
