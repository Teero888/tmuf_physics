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
    
    var file = pak.Files.Values.FirstOrDefault(x => x.Name.Contains("03087AFCAF9BD557046938047A36D3614B"));
    if (file != null) {
        System.Console.WriteLine($"Found {file.Name} at Offset: {file.Offset}, CompressedSize: {file.CompressedSize}, UncompressedSize: {file.UncompressedSize}");
        
        using var fs = File.OpenRead(pakPath);
        fs.Position = file.Offset;
        // The data might be uncompressed if CompressedSize == 0 or equal to UncompressedSize
        int size = file.CompressedSize > 0 ? (int)file.CompressedSize : (int)file.UncompressedSize;
        var data = new byte[size];
        fs.Read(data, 0, data.Length);
        
        File.WriteAllBytes("raw_solid.bin", data);
        System.Console.WriteLine("Saved to raw_solid.bin");
    } else {
        System.Console.WriteLine("File not found in Pak");
    }
}

Run().GetAwaiter().GetResult();
