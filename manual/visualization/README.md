# Interactive physics test

The visual test is a deliberately small SDL2 wireframe viewer. Its shared step
helper mirrors the replay harness's 100 Hz vehicle, wheel-contact, gravity, and
track-collision ordering. The default input is A01's original
`A01-Race.Challenge.Gbx`; its collision is extracted from `Stadium.pak` once
and then reused from the system temporary cache.

Build and run it from `manual/visualization`:

```sh
./build.sh
./interactive_physics_test
```

Controls:

- `W`/Up: accelerate
- `S`/Down: brake or reverse
- `A`/`D` or Left/Right: steer
- `C`: switch between chase and heading-up top-down cameras
- Mouse wheel: camera distance or top-down zoom
- Space: pause
- `N`: advance one 10 ms physics step while paused
- `R`: reset to the spawn
- Escape: quit

Speed, simulation time, position, grounded-wheel count, camera mode, and the
number of visible collision triangles are shown in the window title. Green
wheel marks have ground contact, red marks do not, and the orange line is the
driven trajectory.

To load another TMNF map and choose its spawn:

```sh
./interactive_physics_test /path/to/map.Challenge.Gbx \
  --packs /path/to/TMNF/Packs \
  --start 171.2 90.21 688.0 --yaw 90
```

An existing `.tmnfcol` remains accepted as input. Force regeneration after
extractor development with `--rebuild-map-cache`, or select a cache location
with `--cache-dir PATH`.

The extractor can also be run explicitly for inspection:

```sh
dotnet run --project ../TrackCollisionExtractor -- \
  /path/to/map.Challenge.Gbx ../../steamdata/Packs /tmp/map.tmnfcol
```

For a noninteractive startup/render smoke test:

```sh
SDL_VIDEODRIVER=dummy ./interactive_physics_test \
  --frames 3 --screenshot /tmp/tmnf-physics.bmp
```

This viewer exposes the physics currently implemented by the decompilation;
it does not hide the known collision and vehicle-model parity gaps.
