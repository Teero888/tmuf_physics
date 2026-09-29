# Status

Last updated 2026-09-29.

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
- Ground truth (per-tick trajectories, `~/software/tmuf_oracle/run2..4`,
  `roll1`): 300 local replays (all campaign environments), 3 103 valid TMX
  replays (tmnf + tmuf exchange), 4 611 replays from TMX searches for kacky,
  press-forward, trial, maze, offroad and similar maps
  (`tools/corpus/fetch_corpus.py --query`), 1 464 random rollouts (see
  Tools) and 3 365 TAS replays (`tas_rs`, rebased and resampled, see
  below). 420 replays the game itself cannot simulate are left out:
  "Wrong Simu" or no verdict on maps with block infos the stock game lacks
  (357 need the TMUnlimiter mod).
- The game validates at ~0.7 ms per tick under Wine (~1 400 ticks/s, our
  dumper included) plus ~19 s to start per replay (one launch per replay:
  ~21 s each, ~21 h for 3 500 replays on one worker).
- TAS replays (tmtas.exchange) record their events on another clock (the
  race starts at `_FakeIsRaceRunning`, 165535 instead of 100000). The
  controls start the race at that event. The validator samples the ghost on
  the game's own clock and stops TAS replays right after the start, so they
  go to the oracle rebased and resampled (`make_rollouts.py --resample`):
  the events moved to 100000 and the samples rewritten from our simulation.
- The validator compares the car's position every 100 ms with the ghost's
  samples (sample i: the car at 2 590 + 100 i ms, or the respawn location
  when the next tick respawns) and stops the run ("Wrong Simu") when they
  differ; nothing else in a sample is checked. Of the ghost's fields it
  checks the race time and the respawn count (every respawn press while
  racing counts) and, on Stunts maps, the stunt score; checkpoint times and
  their stunt scores are not checked. It accepts uncompressed bodies, zero security keys and any
  exe hash.

## Parsing (src/common)

- Crypto, zlib 1.2.3 (vendored, the game's version), LZO, packlist, packs.
- Pack stream emulating CClassicBufferCrypted + CClassicBufferZlib with the
  game's page feedback; see docs/pack-format.md.
- GBX reader following CMwNod::Archive exactly, with chunk flags generated
  from the game's GetChunkInfo (Unicorn emulation) and class tables
  (hierarchy, id wrap/unwrap) extracted from the exe.
- Replays (inputs, ghosts, embedded map) and maps (blocks): every corpus
  replay parses. Ids follow CMwId::Archive: only values with the
  0x40000000/0x80000000 name flag are names (28-bit lookback index), others
  stay numeric (edited maps store 0xfffffffe).
- Pack classes, verified byte- and feedback-exact against traces from one
  replay per environment (4926 files, 3646 exact): solids 2363/2368,
  materials 560/560, every block info variant, zones, vehicle tunings and
  structs, mobils 95/124.

## Reference backend (src/reference)

Matches the game bit for bit on all 6 929 oracle replays (all environments,
`tools/sim/run_api_corpus.sh`), on 1 464 random rollouts (1.48 million
ticks of random driving) and on 3 365 TAS replays. Replays the game itself rejects ("Wrong Simu") are
compared up to where the game stops them (it puts the car back at the spawn,
also right at the race start). Includes an hour-long 60-lap replay with
respawns (360855 ticks, 11 s).

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
  laps, spawn locations, respawn, freewheel reset. Laps come from the
  ghost's race settings (`<laps>`, digit groups as the game writes them),
  else the map's for a lap race, else 1 (InitNbLapsAndCheckpoints); the
  checkpoint count is the number of blocks with way type 2 and a
  TriggerCheckpoint/TriggerFinishLine child mobil (PrepareCheckpoints).
- x87 arithmetic: the game computes with 24-bit precision control, which
  equals float math except below the float range; the world inverse inertia
  (GmMat3::Mult/SetMult/MultTranspose) is computed with the x87's unbounded
  exponent (an almost axis-aligned car produces subnormal products there).

## Scene (src/common/scene.c, scene_ctn.c)

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

## Race details and writing replays

- `tmuf_race` holds the race's progress: checkpoints taken, laps, respawns,
  finish time, and `checkpoint_times` (every checkpoint crossing, the finish
  line of each lap included). They equal the ghosts' checkpoint lists on
  300 of 300 sampled valid replays (up to 480 crossings).
- Stunts (src/common/stunts.c, `tmuf_race.stunts`): CTrackManiaRace's
  UpdateStunts / ComputeStunt / ResetStunts, the respawn penalty and the
  Stunts mode time limit, ported from the exe. The game scores stunts in
  every mode; the validator checks the score on Stunts maps, so the library
  scores stunts only there unless a track is loaded with
  `TMUF_TRACK_STUNTS` (the checks use it to compare Race mode ghosts too).
  Details that
  took the game's own trace to find (`run_oracle.py --trace stunts`, a hook
  in ComputeStunt): the car's location the stunts read lags the body by one
  step (the contact flags do not); the first rotation in the air is measured
  from the oldest of the last 20 locations; a master jump means no input
  event in the air, also one that leaves the input as it was (a second
  steering key), which `tmuf_input.input_event` carries. The score matches
  the ghosts of all 137 valid Stunts mode replays and the game's per-jump
  trace; on Race maps a ghost keeps the score of the live drive, which the
  validation does not always reproduce (it does not check it there).
- The whole corpus through the public API (both backends): respawns,
  checkpoint times and Stunts mode scores equal the recorded ones on all
  6 812 valid finished runs (ghosts keep the first 1 000 checkpoint
  crossings); 5 Race mode ghosts keep a live-drive stunt score.
- TAS replays (tmtas.exchange, 3 516, run rebased and resampled): 3 320
  valid in the game, 125 on puzzle maps (the validator refuses those), 54
  invalid (they do not finish in the game either). All 3 365 with a
  trajectory match on both backends (9 more are TMUnlimiter maps the stock
  game cannot load, excluded). Open: on a 66-lap exploit map (4047) that
  crosses the checkpoint and the finish several times per tick, one crossing
  lands a tick later than in the ghost (the order of trigger contacts within
  a tick; physics and finish time match).
- `tmuf_replay_write` (src/common/replay_write.c) saves a run as a replay in
  the game's layout (one CGameCtnGhost, uncompressed body, samples in stored
  zlib blocks). Both backends write identical bytes. `tmuf_rewrite` writes a
  replay's inputs anew; in the game, 136 of 138 rewritten corpus replays
  validated before the stunt score was computed (the other two were Stunts
  maps); since then, 24 of 24 rewritten Stunts mode replays validate.

## Optimized backend (src/optimized)

Bit-identical to the reference on the same 6 929 oracle replays, 1 464
rollouts and 3 365 TAS replays, about 2.2x faster on one core (A01-Race:
210 000 ticks/s with
random inputs, 100 500 on the author's replay). What it does and every
optimization with its measured gain: docs/performance.md.

## Not done yet

- Rendering data export, frametee integration.

## Tools

- `build-rel/tmuf_sim PACKS REPLAY ORACLE [--verbose] [--print]`, `--batch`
  (reference build, `-DTMUF_PHYSICS_TOOLS=ON`). `TMUF_SIM_TRACE=1` prints the
  car's contacts; `tools/dev/cmp_contacts.py` compares them with an oracle
  physics trace (`run_oracle.py --trace physics`). `TMUF_SIM_SNAPTEST=1`
  checks snapshots (a clone restored from them must step identically).
- `tmuf_api_check PACKS LIST` drives replays through the public API with
  world copies and compares every tick with the oracle; LIST lines are
  `REPLAY ORACLE VERDICT` (the game's verdict, `Is_Valid`, `Is_Invalid`,
  `Wrong_Simu`). `tools/sim/run_api_corpus.sh LIST OUT JOBS` runs it in
  parallel (`TMUF_API_CHECK` selects the binary, e.g. the optimized build's).
- `tmuf_bench PACKS MAP [--ticks N] [--seed S] [--replay R]`: single-thread
  ticks per second (thread CPU time).
- `tmuf_rewrite PACKS IN OUT`: a replay's inputs through
  `tmuf_replay_write` (the writer's round trip, for the game to validate).
- Rollouts: `tools/oracle/make_rollouts.py --packs PACKS --build build-rel
  --out DIR --per N LIST` makes replays that keep a replay's inputs up to a
  random time, then drive randomly (`tmuf_rollout`), with the ghost samples
  rewritten from our simulation so the game plays them to the end; run them
  through `run_oracle.py` like any replay. `--resample` keeps the inputs
  (rebased to the game's clock) and only rewrites the samples.
- `run_oracle.py --trace stunts --build DIR` (a dumper built with `make
  OUT=DIR`) logs every stunt the game scores (figure, points, multiplier,
  the race's stunt state); `TMUF_STUNTS_DEBUG=1 tmuf_sim ...` prints ours.
- `tmuf_api_check` also compares the race details a valid run recorded
  (respawns, checkpoint times, Stunts mode scores) with ours.
- `run_oracle.py --trace cells` dumps the game's static collision octree
  (compare with `TMUF_SIM_CELLS=FILE tmuf_sim ...`).
- `tools/dev/fmath_check.sh`: the optimized backend's sin/cos/tan/atan/exp
  against the reference's on all 2^32 floats. `-DTMUF_TRI_CHECK`: the
  optimized backend runs the float triangle test on every triangle its
  reject test skips and aborts on a contact.
- `tmuf_inspect scene PACKS MAP OUT` dumps static triangles
  (`TMUF_SCENE_BLOCKS` tags them, `TMUF_SCENE_DEBUG` traces assembly);
  `tools/dev/cmp_tris.py` compares two such dumps.

## Scene notes

- Flow (replay preload): collection + decoration size, automatic
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
