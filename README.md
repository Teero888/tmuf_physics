# tmuf_physics

TrackMania Nations/United Forever physics in C, bit-exact with the original
game (TmForever 2.11.26). It covers all seven United environments and their
vehicles: a replay simulated with this library produces the same car state,
float for float, as the game on every tick.

The library contains two implementations of the same physics, selected at
compile time:

| Backend     | Directory        | Purpose                                     |
| ----------- | ---------------- | ------------------------------------------- |
| `reference` | `src/reference/` | Readable, follows the game's code structure |
| `optimized` | `src/optimized/` | Fast; must stay in parity with `reference`  |

The two backends never share a source file. Code both of them need (GBX, pack
and replay parsing, map construction into plain data) lives in `src/common/`.

## Status

- Both backends match the game tick for tick on all 6 929 oracle replays
  (local, TMX and kacky-style maps, all environments) and on 1 464 random
  rollouts (1.48 million ticks of random driving the game confirmed).
- Single core, A01-Race: the reference runs 95 000 ticks/s with random
  inputs (about 950x real time), the optimized backend 208 000 ticks/s. The
  game itself validates at about 1 400 ticks/s.

Details: [docs/status.md](docs/status.md) (what is ported and how it is
verified), [docs/performance.md](docs/performance.md) (benchmarks and every
optimization with its measured gain), [docs/pack-format.md](docs/pack-format.md).

## Requirements

- A C11 compiler (GCC, Clang or MSVC), CMake 3.18+
- The `Packs` directory of a TrackMania United Forever installation. Nations
  Forever alone lacks the six non-Stadium environments.

## Build

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DTMUF_PHYSICS_BACKEND=optimized
cmake --build build
ctest --test-dir build
```

Options: `TMUF_PHYSICS_BACKEND` (`reference` or `optimized`),
`TMUF_PHYSICS_SHARED` (shared library), `TMUF_PHYSICS_TOOLS` (the
development tools in `tools/sim`).

Do not add `-ffast-math`, `/fp:fast` or FMA contraction: the physics depends on
exact IEEE single-precision results. The CMake project sets the required
flags itself.

## Usage

```c
#include <tmuf_physics/tmuf_physics.h>

char err[256];
tmuf_packs *packs = tmuf_packs_open(".../TrackMania United/Packs", err, sizeof err);

/* a replay brings its map, car, validation seed and inputs */
tmuf_replay *replay = tmuf_replay_load(data, size, err, sizeof err);
size_t map_size;
const void *map = tmuf_replay_map(replay, &map_size);
tmuf_track_options opt = {tmuf_replay_vehicle(replay), tmuf_replay_seed(replay), tmuf_replay_laps(replay), 0};
tmuf_track *track = tmuf_track_load(packs, map, map_size, &opt, err, sizeof err);

tmuf_world world = tmuf_world_empty();
tmuf_world_init(&world, track);
const tmuf_input *in;
uint32_t n = tmuf_replay_inputs(replay, &in);
for (uint32_t i = 0; i < n; i++) {
  world.input = in[i];     /* accelerate, brake, respawn bits; steer -65536..65536 */
  tmuf_world_tick(&world); /* one 10 ms tick */
}
/* world.sim.body.state (the game's CHmsDyna state), world.sim.car,
   world.sim.race: completed, finish_time, respawns, checkpoint_times[] (every
   checkpoint crossing, finish lines of each lap included), ... */

tmuf_world copy = tmuf_world_empty();
tmuf_world_copy(&copy, &world); /* about a microsecond: branch a search here */
```

Any run can be saved as a replay the game plays and validates:

```c
size_t size;
void *gbx = tmuf_replay_write(track, inputs, count, NULL, &size, err, sizeof err);
/* write gbx to a .Replay.Gbx file */
tmuf_free(gbx);
```

A world starts at time 0 on the start block and is held for the countdown;
the race starts at `TMUF_RACE_START_MS`. There is no global mutable state:
packs and tracks are immutable once loaded and can be shared by any number of
threads, and each world belongs to one thread at a time. All physics structs
are public (`include/tmuf_physics/state.h`) and mirror the game's.

## Parity testing

- `tools/corpus/fetch_corpus.py` downloads replays from tmtas.exchange,
  tmnf.exchange and tmuf.exchange.
- `tools/oracle/` holds the state dumper that records the per-tick vehicle
  state of the original game running under Wine (`run_oracle.py`), for
  tick-by-tick comparison.
- `tools/sim/run_api_corpus.sh` runs replays through the public API (with
  world copies) against those dumps, for either backend.
- `tools/oracle/make_rollouts.py` turns existing replays into new test
  cases: the recorded inputs up to a random time, then random driving,
  rewritten so the game's validator plays them to the end.
