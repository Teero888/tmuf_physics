# TMNF track collision extractor

This development tool converts a TMNF challenge and the original Stadium PAK
into the compact `TMNFCOL1` cache consumed by the standalone C++ physics
library. `Track/TrackMapLoader` invokes it automatically for a
`.Challenge.Gbx` input and reuses a fingerprinted cache on later loads. It does
not guess solid filenames. For every placed block it reads:

1. `CGameCtnBlock.IsGround`, variant, and direction from the challenge.
2. The matching `CGameCtnBlockInfo` from `Stadium.pak`.
3. The selected Ground/Air mobil and its external `CPlugSolid`.
4. Every collidable `CPlugSurface.Mesh` in the solid tree, including tree and
   block transforms and the original physical material ID.

The physics harness and visualization now default to A01's
`A01-Race.Challenge.Gbx`; no manual export is needed. From `manual/`, the old
explicit export command is still available for inspecting the cache:

```sh
./export_a01_collision.sh
```

The output is deliberately ignored by Git because it is derived from the
user's original game data. The binary format is little-endian:

- 8-byte magic `TMNFCOL1`
- four `uint32_t` values: vertex count, triangle count, placed-block count,
  reserved
- vertices as three `float` values
- triangles as three `uint32_t` indices, three normal `float` values, plane
  distance `float`, material `uint16_t`, reserved `uint16_t`

`StadiumGrassClip` instances are terrain-cut metadata and intentionally do not
resolve to a static collision mobil. Dynamic gameplay trigger mobils are also
outside this static cache.

The extractor is an isolated bridge, not the final self-contained solution.
Map headers and placed blocks are already parsed in native C++, but encrypted
PAK access and the `CGameCtnBlockInfo`/`CPlugSolid`/`CPlugSurface` node readers
still come from GBX.NET. Replacing those pieces is the remaining native map
loading task.
