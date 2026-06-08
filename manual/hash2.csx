using System;
using System.Security.Cryptography;
using System.Text;

var variations = new string[] {
    "BaseGround.Solid.Gbx",
    "baseground.solid.gbx",
    "Media/Solid/Circuit/Road/BaseGround.Solid.Gbx",
    "media/solid/circuit/road/baseground.solid.gbx",
    "Media\\Solid\\Circuit\\Road\\BaseGround.Solid.Gbx",
    "media\\solid\\circuit\\road\\baseground.solid.gbx",
    "Stadium/Media/Solid/Circuit/Road/BaseGround.Solid.Gbx",
    "stadium/media/solid/circuit/road/baseground.solid.gbx",
    "Stadium\\Media\\Solid\\Circuit\\Road\\BaseGround.Solid.Gbx",
    "stadium\\media\\solid\\circuit\\road\\baseground.solid.gbx"
};

foreach (var v in variations) {
    var hash = MD5.HashData(Encoding.UTF8.GetBytes(v));
    var hashStr = Convert.ToHexString(hash);
    System.Console.WriteLine($"{v} -> {hashStr}");
}
