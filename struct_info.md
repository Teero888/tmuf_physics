Taken from https://wiki.xaseco.org/wiki/ManiaPlanet_internals


# ManiaPlanet Internals

> This document details the technical **inner workings of ManiaPlanet** (and the original TrackMania).  
> It describes the game's classes, data structures, and functions — geared toward **reverse engineers and programmers**.

---

## Table of Contents

- [Basic Data Types](#basic-data-types)
- [Basic Data Structures](#basic-data-structures)
  - [FastArray](#fastarray)
  - [FastBuffer](#fastbuffer)
  - [String](#string)
  - [FastString](#faststring)
  - [StringInt](#stringint)
  - [FastStringInt](#faststringint)
  - [Id](#id)
  - [Identifier](#identifier)
  - [Delegate](#delegate)
  - [Color](#color)
  - [Vectors / Matrices](#vectorsmatrices)
- [Object System](#object-system)
  - [Runtime Class Inspection](#runtime-class-inspection)
  - [Late Binding](#late-binding)
  - [Serialization](#serialization)
- [I/O](#io)
  - [File and Folder Structure](#file-and-folder-structure)
  - [Loading Files](#loading-files)
  - [Streams](#streams)
    - [CClassicBuffer](#cclassicbuffer)
    - [CClassicBufferPart](#cclassicbufferpart)
    - [CClassicBufferMemory](#cclassicbuffermemory)
    - [CSystemFile](#csystemfile)
    - [CSystemFileMemMapped](#csystemfilememmapped)
    - [CClassicBufferZlib](#cclassicbufferzlib)
    - [CClassicBufferCrypted](#cclassicbuffercrypted)
    - [CClassicArchive](#cclassicarchive)
    - [CSystemArchiveNod](#csystemarchivenod)
- [Tools](#tools)

---

## Basic Data Types

Nadeo uses its own primitive data types in its game engine. Since they can't be reversed, they are not used on this page and are listed here only for completeness.

```cpp
typedef int Integer;
typedef unsigned int Bool;
typedef unsigned char Nat8;
typedef unsigned short Nat16;
typedef unsigned int Natural, Nat32;
typedef unsigned __int64 Nat64;
typedef float Real, Real32;
```

---

## Basic Data Structures

### FastArray

Simple list of items. Resizing allocates exactly the amount of memory needed for the new size, copies the original data, and frees the original buffer.

```cpp
struct FastArray<T>
{
    int size;          // Number of elements in list
    T* pElems;         // Pointer to array of elements
};
```

### FastBuffer

Simple list of items, comparable to `std::vector`. Resizing checks capacity; if insufficient, reallocation occurs to a higher capacity.

```cpp
struct FastBuffer<T>
{
    int size;          // Number of elements in list
    T* pElems;         // Pointer to memory buffer
    int capacity;      // Max elements before reallocation
};
```

### String

Zero-terminated ASCII string. Empty string: `size == 0` **and** `psz` points to a specific empty string (0 byte).

```cpp
struct String
{
    int size;          // Number of characters, excluding terminating 0
    char* psz;         // Pointer to text
};
```

### FastString

Intermediate class used for assigning `char*`/String to String (e.g., `String str, str2; str = "abc"; str2 = str`).

```cpp
struct FastString
{
    char* psz;
    int size;
    String* pStr;
};
```

> **Note:** Order of `psz` and `size` is reversed compared to `String`.

### StringInt

"International" string: zero-terminated UTF-16 (wchar_t). Empty string: `size == 0` **and** `pwsz` points to empty UTF-16 string.

```cpp
struct StringInt
{
    int size;
    wchar_t* pwsz;
};
```

### FastStringInt

UTF-16 equivalent of `FastString`.

```cpp
struct FastStringInt
{
    wchar_t* pwsz;
    int size;
    bool bAscii;       // True if string contains only ASCII-convertible chars
};
```

### Id

Stores a numerical or textual identifier. Uses a global 2D table indexed by hash for fast comparison.

```cpp
struct Id
{
    int value;
};
```

- **Bits 30 & 31 not set** → numerical ID (`value` = ID)
- **Bit 30 or 31 set** → textual (row/col index into global string table)
- **Both bits set** → empty (`value` = -1)

Managed by `CMwId`.

### Identifier

Stores three `Id`s: object name, collection, author.

```cpp
struct Ident
{
    Id id;          // Name (map, block, file path, etc.)
    Id collection;  // Environment (e.g., Canyon = 0xC, Storm = 0xCA)
    Id author;      // Usually "Nadeo"
};
```

Managed by `SGameCtnIdentifier`.

### Delegate

Stores a reference to a member function.

```cpp
struct Delegate
{
    void* pInstance;   // Object instance
    void* pMethod;     // Pointer to method code
};
```

### Color

```cpp
struct Color
{
    float r, g, b;
};
```

### Vectors/Matrices

```cpp
struct Int2 { int x, y; };
struct Int3 { int x, y, z; };
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };
struct Quat { float w, x, y, z; };

struct Iso3 {
    const float AxeXx, AxeXy, AxeYx, AxeYy;
    float tx, ty;
};

struct Iso4 {
    const float AxeXx, AxeXy, AxeXz;
    const float AxeYx, AxeYy, AxeYz;
    const float AxeZx, AxeZy, AxeZz;
    float tx, ty, tz;
};
```

---

## Object System

ManiaPlanet has a custom object system supporting:

- **Reflection**
  - Runtime type identification
  - Late binding (access by name)
- **Serialization** (read/write from `.gbx`)

Root class: **`CMwNod`** — all participating classes derive from it.

### Runtime Class Inspection

Each class described by `CMwClassInfo` → grouped in `CMwEngineInfo` → managed by singleton `CMwEngineManager`.

Key structures:

```cpp
class CMwEngineManager { ... };
class CMwEngineInfo { ... };
class CMwClassInfo { ... };
struct CMwMemberInfo { enum eType { ... }; ... };
```

### Late Binding

Use `CMwStack` to access properties/methods by name.

#### Example: Get Property

```cpp
List<class CPlugSolid*>& CFuncClouds::GetSolidFids() const
{
    static CMwMemberInfo* pMemberInfo = MwGetClassInfo()->GetMemberInfo("SolidFids");
    struct { List<class CPlugSolid*>* pResult; List<class CPlugSolid*> storage; } result;
    CMwStack stack;
    stack.Push(pMemberInfo);
    GetProperty(&stack, &result);
    return *result.pResult;
}
```

#### Example: Set Property

```cpp
void CFuncClouds::SetSolidFids(List<class CPlugSolid*>& value)
{
    static CMwMemberInfo* pMemberInfo = MwGetClassInfo()->GetMemberInfo("SolidFids");
    CMwStack stack;
    stack.Push(pMemberInfo);
    CallMethod(&stack, &value);
}
```

#### Example: Call Method

```cpp
uint CGameCtnEditorPluginScriptHandler::CanPlaceBlock(CGameCtnBlockInfo* pBlockModel, int3 coord, uint dir)
{
    static CMwMemberInfo* pMemberInfo = MwGetClassInfo()->GetMemberInfo("CanPlaceBlock");
    uint uiVariantIndex;
    CMwStack stack;
    stack.Push(pMemberInfo);
    stack.Push(dir);
    stack.Push(coord);
    stack.Push(*reinterpret_cast<CMwNod**>(&pBlockModel));
    stack.Push(uiVariantIndex);
    CallMethod(&stack, NULL);
    return uiVariantIndex;
}
```

### Serialization

Use `CSystemArchiveNod` to load/save `.gbx` files:

```cpp
int CSystemArchiveNod::LoadFromFid(CMwNod** ppResultNod, CSystemFid* pFid, enum EArchive = 7);
int CSystemArchiveNod::LoadFileFrom(CFastStringInt* pwstrFilePath, CMwNod** ppResultNod, CSystemFids* pFolder, enum EArchive);
int CSystemArchiveNod::SaveFile(CFastStringInt* pwstrFilePath, CMwNod* pNod, CSystemFids* pFolder, enum EArchive, int);
```

---

## I/O

### File and Folder Structure

ManiaPlanet uses **drives** (isolated folders):

| Drive       | Source |
|-------------|--------|
| `Resource`  | `Packs\Resource.pak` |
| `Personal`  | User maps/settings |
| `ManiaPlanet` | `ManiaPlanet.exe`, `GameData` |
| `Common`    | `PacksCache`, etc. |
| `Temp`      | Temporary files |

Files merged from `.pak`/`.zip` into in-memory structure.

Root drives managed by `CSystemEngine` → `CMwEngineMain`.

### Loading Files

```cpp
class CLoader
{
    virtual CClassicBuffer* OpenBuffer(CSystemFid const* pFid, enum EMode, int) const;
    virtual void CloseBuffer(CSystemFid const* pFid, CClassicBuffer* pBuffer) const;
};
```

### Streams

#### CClassicBuffer

Abstract base stream (like C# `Stream`).

#### CClassicBufferPart

Exposes subsection of another stream.

#### CClassicBufferMemory

In-memory stream (like `MemoryStream`).

#### CSystemFile

Buffered file read (4 KB chunks).

#### CSystemFileMemMapped

Memory-mapped file.

#### CClassicBufferZlib

Zlib compression/decompression.

#### CClassicBufferCrypted

Encryption/decryption (Blowfish CBC/CTR + custom XOR).

#### CClassicArchive

Binary reader/writer wrapper over `CClassicBuffer`.

#### CSystemArchiveNod

Specialized for `.gbx` files. Handles header, ref table, body.

---

## Tools

- **[TM2Unlimiter](https://web.archive.org/web/20120531221658/http://forum.mania-creative.com/thread-2983.html)**  
  Open-source tool with up-to-date ManiaPlanet function addresses.

---

> **License**: Content is available under [CC BY-SA 4.0 International](https://creativecommons.org/licenses/by-sa/4.0/) unless otherwise noted.  
> Retrieved from: [ManiaPlanet internals - Mania Tech Wiki](https://wiki.xaseco.org/wiki/ManiaPlanet_internals) (last edited 30 June 2017)
