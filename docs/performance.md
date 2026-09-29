# Performance

Single-threaded throughput of `tmuf_world_tick` on the Nations campaign map
**A01-Race** (Stadium, StadiumCar), measured with `tools/sim/tmuf_bench`
(commit d48dfcc, 2026-09-28).

## Results

| backend   | random inputs (ticks/s) | author replay (ticks/s)   | per tick (random) |
|-----------|-------------------------|---------------------------|-------------------|
| reference | **95 000**              | 48 000 (best run 48 400)  | 10.5 µs           |
| optimized | **208 000**             | 100 500 (best run 102 300)| 4.8 µs            |

One tick is 10 ms of game time, so on one core the reference runs about
950× real time with random inputs (480× on the author's run), the optimized
backend about 2 100× (1 000×). For comparison, the game itself validates a
replay at about 1 400 ticks/s under Wine (see the oracle numbers in
docs/status.md).

- Random inputs: runs of 1 000 000 ticks (seeds 1–5), each an episode of
  3 000 ticks (30 s, countdown included) from the start, restarted with
  `tmuf_world_copy` of the time-0 world. Inputs are held for 1–20 ticks:
  accelerate 80 %, brake 15 %, steering full left / full right / straight /
  analog. The runs agree within 2–3 % (reference 93 100–96 600, optimized
  204 200–209 300 ticks/s); single runs can be lower when other programs
  start on the machine.
- Author replay: the A01-Race.Replay.gbx shipped with the game (24.54 s,
  2 715 ticks), run 369 times; it finishes at the recorded time. It is
  slower per tick than random inputs: the car is fast, and the game splits
  a tick into more substeps the faster the car goes (3.3 per tick on
  average here, 1.04 with random inputs); each substep runs the whole
  collision detection.

Other costs (both backends):

| what                          | cost          |
|-------------------------------|---------------|
| `tmuf_world_copy` (same track) | 0.4–1.1 µs   |
| `sizeof(tmuf_world)`          | 19 888 bytes  |
| `tmuf_packs_open`             | 0.06–0.09 s   |
| `tmuf_track_load` (A01-Race)  | 0.24 s        |

## Where the time goes (reference)

Measured with `perf record -e task-clock` on the random-input benchmark:

- **Collision detection ~80 %**: the car's eight body ellipsoids walk the
  static octree (~20 cells each per substep) and, for every block they
  reach, that block's mesh tree (~44 cells per walk); about 50 triangle
  tests per substep, 0.4 contacts per ellipsoid–mesh pair.
- Car forces (wheels, engine, steering, air control) ~14 %.
- Collision response (sort, impulses) ~5 %.
- Integration < 2 %.

## Optimized backend

`src/optimized` produces bit-identical states (checked with
`tools/sim/run_api_corpus.sh` on all 6 929 oracle replays the game itself
can simulate and on 1 464 random rollouts, see docs/status.md). The speed-up
comes from doing the same work with less overhead, not from different
arithmetic:

- all car trees walk the static tree and each reached mesh once, every
  cell tested against all trees at once (SSE/AVX; same operations as the
  game's box test); the static walk records which trees reach each record,
  and the collisions are made afterwards in the reference's order;
- ellipsoid–triangle tests four triangles at a time (AVX: vertices and
  normal with the float operations per lane, the vertices read from a
  per-mesh packed copy built at load); a triangle is skipped without a root
  or division when a double-precision test shows, with a margin far above
  the float rounding error, that the float test finds no contact (86 % of
  the triangles on A01-Race; `-DTMUF_TRI_CHECK` runs the float test on
  every skipped triangle and aborts on a contact: none on the whole
  corpus);
- sin, cos, atan2, exp evaluate their series by Horner; a result within
  2^8 double ulps of a float rounding midpoint falls back to the
  reference's series, so the float results are the same
  (`tools/dev/fmath_check.sh` compares all 2^32 inputs);
- ellipsoid transforms built only when a triangle is reached; no debug
  hooks in the tick path; mesh cells read in place; single-precision
  `sqrtf` (provably the same result as the reference's double root
  rounded); the backend compiles as one unit (`unity.c`) so the small
  helpers inline across files;
- the few places where the game's x87 arithmetic differs from float math
  (the world inverse inertia: products below the float range) take the
  float path unless a matrix entry is tiny.

Per tick (random inputs) the optimized backend spends about half its time
in collision detection (walks and triangles), the rest in car forces,
collision response and integration.

## Optimization log (optimized backend)

Each change was measured with `bench_ab` style interleaved runs (A01-Race,
random inputs, thread CPU time, best of 4–6 runs, the benchmark alone on
one physical core). The gain is the speed ratio against the build just
before the change; the absolute numbers drift a little between sessions
(background load), so only ratios are comparable. Every kept change is
bit-exact: the whole oracle corpus matches.

| # | change | gain | ticks/s after |
|---|--------|------|---------------|
| 1 | copy of the reference; debug hooks (`getenv`) out of the tick path; ellipsoid transforms in `ellipsoid_mesh` built only when a triangle is reached | +16 % over the reference | 106 k |
| 2 | skip worlds without records (triggers, non-static) | +0.3 % | 106 k |
| 3 | mesh cells tested in place (no `mesh_cell` copy per cell) | +2.7 % | 108 k |
| 4 | cell fields read with direct scalar loads (`ld_f32`) | +3.1 % | 111 k |
| 5 | `sqrtf` inline instead of `(float)sqrt((double)x)` (same result, proven) | +1.1 % | 112 k |
| 6 | combined detection: all car trees walk the static tree once and each reached mesh once, every cell tested against all trees with SSE; collisions made afterwards in the reference's order | +19 % | 133 k |
| 7 | the trees' world locations and boxes gathered once per substep for all three worlds | +7.2 % | 144 k |
| 8 | 8-lane AVX cell test (runtime dispatch) | +4.0 % | 150 k |
| 9 | `tmuf_mul_fd` inline (constant splits fold) | +0.3 % | 150 k |
| 10 | triangle plane reject in double without root/division (`plane_rejects`) | +1.0 % | 152 k |
| 11 | full triangle reject test (`tri_rejects`: plane, then edges via the exact triple product), 86 % of triangles skip the float test | +2.9 % | 157 k |
| 12 | four triangles per step in AVX (vertices, normal, reject test per lane) | +8.5 % | 171 k |
| 13 | the AVX triangle batch inlined into the walk | +4.8 % | 180 k |
| 14 | sin/cos/tan/atan2/exp by Horner with a near-midpoint fallback to the reference series; `sin(0)` shortcut | +3–4 % (measured under load) | 183 k |
| 15 | the backend as one translation unit (`unity.c`, GCC `inline-unit-growth=100`): helpers inline across files, same as LTO | +2.9 % (LTO A/B; unity equal to LTO) | 188 k (199 k once the oracle stopped) |
| 16 | triangle vertices loaded as vectors and transposed (no store-forwarding stalls) | +2.0 % | 203 k |
| 17 | the static walk records which trees reach each record and at which slot (no search per mesh record) | +1.2 % (replay +2.5 %) | 206 k |
| 18 | per mesh surface, each triangle's vertices packed together at load (the batch reads 36 contiguous bytes) | +3.5 % (replay +0.5 %) | 213 k |
| 19 | exactness fix, not a speed-up: the world inverse inertia as GmMat3::Mult rounds it on the x87 (subnormal products); the optimized backend takes the float path unless an entry is below 2^-60 | −0.9 % | 211 k |
| 20 | feature, not a speed-up: stunt figures (src/common/stunts.c, every racing tick: location history, rotation in the air) | −0.5 % random, −0.8 % on a replay with 60 jumps | 210 k |

Tried and dropped (slower or no gain, all exact):

| change | result |
|--------|--------|
| shared static traversal first version (per-cell scalar loop over trees) | 0.85× |
| uniform grid / packed leaf index over mesh triangles instead of the octree walk (several variants) | 0.24–0.87× |
| branch-free cell test (`&` instead of short-circuit), other axis orders | 0.96×, 0.98× |
| SIMD vertex transform per triangle (before batching) | 0.985× |
| active-lane mask in the cell test | 0.98× |
| per-pair vertex cache (shared vertices transformed once) | 1.00× |
| `to_mesh` and ellipsoid boxes for all trees at once (SoA, vectorized) | 0.985× |
| prefetching the reached records | 1.00× |
| one bounding-volume tree over all static triangles and records in world space (built at load), candidates sorted into the walk's order, `to_mesh` only for blocks with candidates, exact reach checked for survivors | 0.80× random, 0.89× replay: an 18-level tree over 215 000 items costs as many box tests per substep as the two-level walk (214 vs 195), and world-space margins give 1.4× the candidates |
| curve key bounds precomputed per track | no measurable gain (the lookup's cost is its scan, not the rounding) |
| handling model 5: repeated pure curve and sine calls with the same argument evaluated once per pass | 1.00× |
| exact detection cache: walks with query boxes inflated by the recent movement, reused while the car stays inside; rejected triangles sleep while the ellipsoid moves less than their gap; contacts checked against the exact walk | 0.68–0.78× random, 0.60–0.69× replay: the inflated candidate sets are 7–15× the exact ones, and even with sleeping more triangles stay awake than the exact walk tests |
| memoizing tree boxes whose location did not change | est. 1 %, not done |
| `-march=native` | 1.015× (not used: portability) |
| profile-guided optimization | 1.00× |

Where the optimized tick goes now (random inputs, 18 500 TSC cycles per
tick at 3.5 GHz, cycle counters): triangle groups 3 800 (about 230 per
group of four), float triangle tests of the survivors 1 800, mesh walks
2 300, `to_mesh` and query boxes 1 500, static walk 1 000, rest of the
collision phase 800; car forces, response and integration about 7 000.

## Setup

Intel Xeon E3-1240 v5 (Skylake, 3.5 GHz, turbo 3.9 GHz), Linux 7.3, GCC 16.2,
`-O3` with the library's exact-float flags (`-ffp-contract=off`, no fast
math). Pinned to one logical CPU with its hyperthread sibling left idle;
the other cores were busy (the oracle), so the numbers use the benchmark
thread's CPU time (`CLOCK_THREAD_CPUTIME_ID`); wall-clock times were within
0.5 % of it.

```
tmuf_bench PACKS A01-Race.Challenge.Gbx --ticks 1000000 --seed 1
tmuf_bench PACKS A01-Race.Challenge.Gbx --replay A01-Race.Replay.gbx
```

Tracks are immutable and shared, worlds are independent: throughput scales
with the number of threads (one world per thread), not measured here.
