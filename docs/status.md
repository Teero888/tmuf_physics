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

- Pack classes: CMotion* (animated mobils), CScene3d, CGameCtnDecoration,
  CGameCtnDecorationSize, CGameCtnCollection, CGameSkin, a few CFunc*.
- Scene assembly: map -> collection/decoration -> block infos -> variants ->
  mobils -> solids -> world-space collision surfaces.
- Physics (reference backend): not started.
- Optimized backend, public API, frametee integration.
