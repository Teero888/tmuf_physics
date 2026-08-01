using System;
using System.IO;
using System.IO.Compression;
using System.Linq;
using GBX.NET.PAK;
using System.Threading.Tasks;

class Program {
    static async Task Main(string[] args) {
        var pakPath = "/home/teero/software/tmnf_physics/steamdata/GameData/Stadium.pak";
        var pakData = File.ReadAllBytes(pakPath);
        var msInput = new MemoryStream(pakData);
        var key = "0FBEA15ACADFEE1638900A5683902A29";
        var pak = await Pak.ParseAsync(msInput, Convert.FromHexString(key).Select(x => (byte)(255 - x)).ToArray(), computeKey: false);
        
        var targetFile = pak.Files.Values.FirstOrDefault(f => f.Name.Contains("03087AFCAF9BD557046938047A36D3614B"));
        if (targetFile != null) {
            Console.WriteLine("Found target file in PAK!");
            using var pakItemFileStream = pak.OpenFile(targetFile, out _);
            var data = new byte[targetFile.UncompressedSize];
            pakItemFileStream.Read(data, 0, data.Length);
            File.WriteAllBytes("RAW_03087AFCAF9BD557046938047A36D3614B", data);
            Console.WriteLine("Saved RAW file.");
        } else {
            Console.WriteLine("File not found in PAK.");
        }
    }
}
