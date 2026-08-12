# Interactive physics test

The visual test is a small SDL2 viewer that draws the collision world either as
shaded solid surfaces or as a wireframe. Its shared step helper mirrors the
replay harness's 100 Hz vehicle, wheel-contact, gravity, and track-collision
ordering. The default input is A01's original `A01-Race.Challenge.Gbx`; its
collision is extracted from `Stadium.pak` once and then reused from the system
temporary cache.

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
- `M`: switch between shaded surfaces and wireframe
- `B`: toggle backface culling (solid mode); off shows both sides of every
  surface, which is the honest view of a collision mesh but draws roughly twice
  as much and reintroduces painter's-algorithm artefacts
- Mouse wheel: camera distance or top-down zoom
- Space: pause
- `N`: advance one 10 ms physics step while paused
- `R`: reset to the spawn
- Close the window to quit (Escape is deliberately not bound)

Start directly in one style with `--solid` (the default) or `--wireframe`.
`--zoom` and `--chase-distance` set the initial camera framing, and
`--help` lists every option and key binding.

The front wheels show their steering angle, and all four show their roll. Both
come from the native per-wheel real-time state: `IntegrateVehicle` drives a
steerable wheel's target to 30 degrees of the smoothed input, and the wheel
integrator walks the visible angle toward it at one radian per second. The
merged StadiumCar mesh has no wheel objects, so the viewer recovers them
geometrically as cylinders about the native attachment points.

Reverse currently does nothing: the flag that selects it is never set. See
`PARITY_STATUS.md` for the missing native producer. Braking as deceleration
does work.

Speed, simulation time, position, grounded-wheel count, camera mode, draw
style, primitive count, and frame rate are shown in the window title. Green
wheel marks have ground contact, red marks do not, and the orange line is the
driven trajectory. On exit the viewer prints the average per-frame physics,
render, and present cost. `--screenshot-frame N` captures a later frame, which
is what makes state that takes time to build up (steering, trail) visible in a
smoke-test capture.

Solid mode shades each face with a fixed key light and fades distant geometry
into the background. SDL's 2D renderer has no depth buffer, so faces are
depth-sorted and drawn back to front; intersecting geometry can therefore show
sorting artefacts, and `M` back to wireframe is the way to check what is
actually there.

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

## Rendering notes

Each mesh is preprocessed once at startup into a deduplicated edge list and a
face list, both indexed by a uniform grid over the XZ plane. Per frame the
viewer walks only the grid cells within the view radius that survive a
horizontal view-wedge test, projects every vertex at most once, and submits the
result through a single batched `SDL_RenderGeometryRaw` call rather than one
SDL draw call per triangle edge.
