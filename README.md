# tmuf_physics

A C library for TrackMania Nations/United Forever (TmForever 2.11.26). It
reads the game's data files and simulates its vehicle physics and race rules
bit-exactly: every tick matches the game float for float, in all seven
environments. It also exposes what the game draws and plays (meshes,
lighting, weather, the car, sounds) as plain data.

The game's files are not included; the library reads them from an install.

## Building

Needs a C11 compiler, CMake 3.18+ and the `Packs` directory of a TrackMania
United Forever install.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DTMUF_PHYSICS_BACKEND=optimized
cmake --build build
```

`TMUF_PHYSICS_BACKEND` picks `reference` (readable, follows the game's code)
or `optimized` (about twice as fast); both give the same results. Never build
with `-ffast-math` or FMA contraction: the physics relies on exact float
results.

## Example

```c
#include <tmuf_physics/tmuf_physics.h>

tmuf_packs *packs = tmuf_packs_open("TrackMania United/Packs", NULL, 0);
tmuf_track *track = tmuf_track_load(packs, map, map_size, NULL, NULL, 0);

tmuf_world world = tmuf_world_empty();
tmuf_world_init(&world, track);
for (int i = 0; i < 1000; i++) {
  world.input = (tmuf_input){.accelerate = 1};
  tmuf_world_tick(&world); /* 10 ms */
}
/* world.sim.body.state: the car; world.sim.race: checkpoints, finish, ... */
```

Replays work the same way: `tmuf_replay_load` gives a replay's map, car and
inputs, and `tmuf_replay_write` turns any inputs into a replay the game
validates. `tmuf_world_copy` copies a world in about a microsecond, for
searches.

The full API is documented in `include/tmuf_physics/tmuf_physics.h`.

## Verification

Both backends match the game tick for tick on 11 758 replays (recorded runs,
random rollouts and TAS replays, all environments), checked against the
game's own state dumped under Wine. See [docs/status.md](docs/status.md) and
[docs/performance.md](docs/performance.md).

## License

AGPL-3.0, see [LICENSE](LICENSE).
