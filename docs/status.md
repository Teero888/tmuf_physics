# Status

Last updated 2026-09-26.

## Oracle (tools/oracle)

- `dumper.dll` + `launcher.exe` (MinGW, run under Wine) hook the TMUF 2.11.26
  exe: per physics tick (`CHmsZoneDynamic::PhysicsStep2`) the end-of-tick
  state of every `CHmsDyna` (180 bytes: quaternion, rotation matrix,
  position, linear/angular velocity, ...). `--trace feedback` logs pack
  stream feedback per file.
- `run_oracle.py` validates replays with `/validatepath` on headless Xvfb
  workers with private Wine prefixes (the account dialog is dismissed with
  Escape; the game then runs offline).
- `symmap.py` maps 48.6k PDB functions (TmForeverFixed.exe) to the TMUF exe.
- Game setup: `~/software/tmuf_oracle/{game,pfx}` (copy of the Steam TMUF
  install, activated profile `steamuser`).
- Ground truth so far: 300 valid local replays (all campaign envs) and the
  TMNF-X world records (Stadium), full per-tick trajectories.
- TAS replays (tmtas.exchange) are rejected by the game's validation right
  at race start (no trajectory), so they need an input-injecting oracle.

## Parsing (src/common)

- Crypto, zlib 1.2.3 (vendored, the game's version), LZO, packlist, packs.
- Pack stream emulating CClassicBufferCrypted + CClassicBufferZlib with the
  game's page feedback; see docs/pack-format.md.
- GBX reader following CMwNod::Archive exactly, with chunk flags generated
  from the game's GetChunkInfo (Unicorn emulation) and class tables
  (hierarchy, id wrap/unwrap) extracted from the exe.
- Replays (inputs, ghosts, embedded map) and maps (blocks): all 1878 corpus
  replays parse except 18 TMUnlimiter maps.
- Pack classes, verified byte- and feedback-exact against traces from one
  replay per environment (4926 files, 3646 exact): solids 2363/2368,
  materials 560/560, every block info variant, zones, vehicle tunings and
  structs, mobils 95/124.

## Not done yet

- Pack classes: CScene3d (decoration scene), CGameSkin, a few CFunc*.
- Scene assembly, remaining: automatic base terrain (default zone), clips,
  pylons, decoration scene; and keeping per-item structure (the game collides
  against a static octree of items, so contact order depends on it).
- Physics (reference backend): not started.
- Optimized backend, public API, frametee integration.

## Scene assembly (src/common/scene.c)

- Explicit map blocks: block infos found by collector identifier (header
  chunk 0x0301a003), ground/air variant, mobil selection, location, item
  solids (following solid models), object links, tree transforms. On the
  "fragmented" test map all 227 blocks resolve and all 125852 emitted
  triangles are bit-identical to the reference static triangles
  (`tools/dev/cmp_tris.py`, `tmuf_inspect scene`).
- Still missing on that map: ground terrain fill, pylons, decoration
  (~80k triangles).
- Decoration and decoration size are loaded (map size, base height).
- Ghidra project of TmForeverFixed.exe + PDB (full types):
  `~/software/tmuf_oracle/ghidra` (`scripts/Decompile.java` dumps functions
  matching regex lists).

## Scene notes

- Reference to compare against: a dev-only tool writes a map's static collision triangles
  (`u32 count`, 9 floats each). "fragmented" (corpus 7260080): 206581.
- Flow (the game's Preload): collection + decoration size, automatic
  base (ground zones), challenge construction (explicit blocks plus
  automatic pylons/clips), per placement mobils -> CHmsItem solid -> tree ->
  surfaces, decoration scene.
- Block flags: variant = f & 0x3f, mobil selection = (f >> 6) & 0x3f (0x3f
  automatic), 0x1000 ground family, 0x2000 creates mobil, 0x4000 custom
  size, 0x8000 skin, 0x10000 secondary source. Mobil =
  variants[ground ? 0 : 1][variant][selection].
- Block size per family: max(unit offset) + 1. Unit chunk 0x03036000:
  junction mask, helper, unused, offset x y z, count, source refs.
- Mobil location: coord * (square size, height, size) (collection: Stadium
  32/8), rotated by quarter turns about Y (rows X = (c,0,-s), Z = (s,0,c));
  East adds size.z*sq to x, South adds size.x to x and size.z to z, West
  adds size.x to z.
- Mesh triangle record (32 B): normal xyz, plane distance, 3 u32 indices,
  u16 local material. Iso4 on disk: rows X Y Z then translation.
- Block info files: <Env>\ConstructionBlockInfo\<Kind>\<Name>.TMED<Kind>.Gbx
  (plain names); collection: Collections\<Env>.TMCollection.Gbx.
