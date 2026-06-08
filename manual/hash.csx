using System;
using System.Security.Cryptography;
using System.Text;

var target = "Media/Solid/Circuit/Road/BaseGround.Solid.Gbx";
var hash = MD5.HashData(Encoding.UTF8.GetBytes(target.ToLowerInvariant()));
var hashStr = Convert.ToHexString(hash);
System.Console.WriteLine($"Hash (lower): {hashStr}");

hash = MD5.HashData(Encoding.UTF8.GetBytes(target));
hashStr = Convert.ToHexString(hash);
System.Console.WriteLine($"Hash (exact): {hashStr}");

var target2 = "Stadium\\Media\\Solid\\Circuit\\Road\\BaseGround.Solid.Gbx";
hash = MD5.HashData(Encoding.UTF8.GetBytes(target2.ToLowerInvariant()));
hashStr = Convert.ToHexString(hash);
System.Console.WriteLine($"Hash2 (lower): {hashStr}");
