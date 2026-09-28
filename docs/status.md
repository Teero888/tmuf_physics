# Status

Last updated 2026-09-28.

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
- Ground truth: 300 valid local replays (all campaign envs) and 3103 valid
  TMX replays (tmnf + tmuf exchange), full per-tick trajectories
  (`~/software/tmuf_oracle/run2`, `run3`; 369 "Wrong Simu", 135 no verdict).
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

## Reference backend (src/reference)

Matches the game bit for bit on all 307 local oracle replays and on all 3472
TMX replays (`tools/sim/run_corpus.sh`, all environments). Replays the
game itself rejects ("Wrong Simu", including all TMUnlimiter maps) are
compared up to where the game aborts them. Includes an hour-long 60-lap
replay with respawns (360855 ticks, 11 s).

Water: zone water grids (Coast, Bay, Island, Alpine) and geometry water planes
(Speed, Rally): CHmsCorpus::WaterGetPlaneEqInZone over the scene's corpora
(tree material -> model device shader -> CPlugShaderApply flags and a
CPlugBitmapRenderWater bitmap; plane at the visual's bounding box), cells
indexed by their ground block's plane (only the first plane is water).

The static collision cells are in the game's order (checked against the
oracle's `cells` trace, tools/oracle/dumper.c): only static-flagged corpora
enter the octree (non-static ones such as StadiumWarpFlags collide in their
own list), and clip sides follow CreateMobilForClip's ReplaceByLastAt order.

- CHmsDyna integration, substeps, collision detection (static octree,
  sphere/ellipsoid/box/mesh), sphere contact merge, collision response.
- CSceneVehicleCar: all handling models, wheels, engine/gears, steering,
  turbo, fake contacts, air control, water (buoyancy, drag, splash).
- Race: checkpoint/finish triggers (collision group 1), checkpoint slots,
  laps, spawn locations, respawn, freewheel reset.

## Scene (src/common/scene.c, scene_ctn.c)

- Challenge construction following the game's
  CGameCtnChallenge: zone grid, field units, automatic base, suppression,
  block mobils, clips (AddClipsToScene/UpdateClip), pylons.
- Static triangles contain every reference triangle on 49 test maps;
  the extra ones are editor helpers (never collided) and mobils with
  emitter-leaves motion (trees), collided but left out of the reference
  dump.
- Material remaps: terrain-modifier skins (CGameCtnDecorationTerrainModifier
  / CPlugGameSkin) for decoration-skin and replacement blocks; collection
  surface replacement pairs decide replacement for ground blocks and clips.
- Water grid (CSceneVehicleWaterZone) from the zones' water flags.
- Decoration decorator (CPlugDecoratorSolid): per-tree collision of the
  decoration's Warp mobil (Stadium: only the Low LOD collides).
- Maps: the map's collection supplies blocks, the decoration may come from
  another; TMUnlimiter pseudo blocks are skipped like the game; maps without
  a start block spawn at the origin; custom vehicle ids use the collection's
  car.

- Pylon columns built from pieces: the middle piece's mesh is raised as
  CreateNewPylonMobil does (vertices above half a square moved up, planes
  recomputed, archived octree kept). No pylon in the shipped packs has a
  middle piece (Snow and Desert use one mesh per height), so no map in the
  corpus uses it.
- Animated block parts (a mobil with a motion, e.g. Rally trees) collide as
  static at their initial location: block mobils are static in the game
  whatever their archived item flags say. Checked against the game's static
  octree (`run_oracle.py --trace cells`) on maps with up to 1 066 animated
  mobils: the same records.

## Not done yet

- Rendering data export, frametee integration.

## Tools

- `build-rel/tmuf_sim PACKS REPLAY ORACLE [--verbose] [--print]`, `--batch`.
  `TMUF_SIM_TRACE=1` prints the car's contacts; `tools/dev/cmp_contacts.py`
  compares them with an oracle physics trace
  (`run_oracle.py --trace physics`).
- `tmuf_inspect scene PACKS MAP OUT` dumps static triangles
  (`TMUF_SCENE_BLOCKS` tags them, `TMUF_SCENE_DEBUG` traces assembly);
  `tools/dev/cmp_tris.py` compares with a reference dump.

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
