#ifndef CPLUGBITMAP_HPP
#define CPLUGBITMAP_HPP

#include "typedefs.h"

struct CDx9TextureKeeper;
struct CPlugBitmapRender;
struct CVisionViewportDx9;
struct GmBoxAligned;
struct GmFrustum;
struct SPlugFaceCull;
struct ulong;
struct ushort;

struct CPlugBitmap {
    void** vftable; // accesses: 15
    byte _padding_0x4[16];
    uint field_0x14; // accesses: 42
    CPlugBitmapRender field_0x18; // accesses: 4
    ulong field_0x1c; // accesses: 4
    ushort field_0x20; // accesses: 10
    ushort field_0x22; // accesses: 5
    ushort field_0x24; // accesses: 8
    ushort field_0x26; // accesses: 4
    byte _padding_0x28[16];
    undefined4 field_0x38; // accesses: 1
    int field_0x3c; // accesses: 4
    byte _padding_0x40[8];
    int field_0x48; // accesses: 2
    uint field_0x4c; // accesses: 2
    byte _padding_0x50[12];
    GmFrustum * field_0x5c; // accesses: 6
    CVisionViewportDx9 * field_0x60; // accesses: 6
    GmBoxAligned * field_0x64; // accesses: 2
    CVisionViewportDx9 * field_0x68; // accesses: 2
    byte _padding_0x6c[4];
    int field_0x70; // accesses: 1
    SCasterCat * field_0x74; // accesses: 2
    uint field_0x78; // accesses: 1
    CPlugBitmap * field_0x7c; // accesses: 3
    CPlugBitmap * field_0x80; // accesses: 1
    CPlugBitmap * field_0x84; // accesses: 1
    byte _padding_0x88[8];
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[16];
    CVisionViewportDx9 * field_0xa4; // accesses: 2
    int field_0xa8; // accesses: 1
    undefined4 field_0xac; // accesses: 1
    CPlugBitmapRender field_0xb0; // accesses: 13
    byte _padding_0xb4[16];
    CPlugBitmapRender field_0xc4; // accesses: 3
};

#endif // CPLUGBITMAP_HPP
