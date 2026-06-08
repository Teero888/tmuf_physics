#r "nuget: GBX.NET, 2.4.2"
#r "nuget: GBX.NET.PAK, 2.4.2"
using GBX.NET;
using GBX.NET.PAK;
using System.IO;
using System.Threading.Tasks;
using System.Linq;

async Task Run() {
    var pakPath = "../steamdata/Packs/Stadium.pak";
    var packlistPath = "../steamdata/Packs/packlist.dat";

    var pakList = await PakList.ParseAsync(packlistPath, PakListGame.TM);
    var keys = pakList.ToKeyInfoDictionary();
    var keyData = keys["Stadium"];
    await using var pak = await Pak.ParseAsync(pakPath, keyData);

    var target = "Media/Solid/Circuit/Road/BaseGround.Solid.Gbx";
    if (pak.Files.TryGetValue(target, out var file)) {
        System.Console.WriteLine($"Found {target}! Hash: {file.Name}");
    } else {
        System.Console.WriteLine($"{target} not found.");
        System.Console.WriteLine($"Checking keys... First 5 keys:");
        int count = 0;
        foreach (var key in pak.Files.Keys) {
            System.Console.WriteLine(key);
            if (++count >= 5) break;
        }
    }
}

Run().GetAwaiter().GetResult();
