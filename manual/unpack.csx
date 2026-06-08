#r "nuget: GBX.NET, 2.4.2"
#r "nuget: GBX.NET.PAK, 2.4.2"
using GBX.NET;
using GBX.NET.PAK;
using System.IO;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Linq;

async Task Run() {
    var pakPath = "../steamdata/Packs/Stadium.pak";
    var packlistPath = "../steamdata/Packs/packlist.dat";
    var outPath = "../steamdata/GameData/Stadium_Extracted";

    System.Console.WriteLine("Parsing packlist...");
    var pakList = await PakList.ParseAsync(packlistPath, PakListGame.TM);
    var keys = pakList.ToKeyInfoDictionary();

    System.Console.WriteLine("Opening Stadium.pak...");
    var keyData = keys["Stadium"];
    System.Console.WriteLine($"Stadium Key: {Convert.ToHexString(keyData)}");
    await using var pak = await Pak.ParseAsync(pakPath, keyData);

    System.Console.WriteLine($"Found {pak.Files.Count} files in Pak. Extracting...");
    foreach (var file in pak.Files.Values) {
        var fullPath = Path.Combine(outPath, file.FolderPath, file.Name);
        Directory.CreateDirectory(Path.GetDirectoryName(fullPath));
        
        await using var stream = File.Create(fullPath);
        try {
            var pakItemFileStream = pak.OpenFile(file, out _);
            pakItemFileStream.CopyTo(stream);
        } catch (System.Exception ex) {
            System.Console.WriteLine($"Failed to extract {file.Name}: {ex.Message}");
        }
    }
    System.Console.WriteLine("Done.");
}

Run().GetAwaiter().GetResult();
