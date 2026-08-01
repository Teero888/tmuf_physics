using System;
using System.IO;
using System.Reflection;
using System.Linq;

class Program {
    static void Main(string[] args) {
        var dll = Assembly.LoadFile("/home/teero/.nuget/packages/gbx.net.crypto/1.2.1/lib/net8.0/GBX.NET.Crypto.dll");
        foreach(var t in dll.GetTypes()) {
            Console.WriteLine(t.FullName);
            foreach(var m in t.GetMethods()) {
                Console.WriteLine("  " + m.Name + " " + string.Join(", ", m.GetParameters().Select(p => p.ParameterType.Name)));
            }
        }
    }
}
