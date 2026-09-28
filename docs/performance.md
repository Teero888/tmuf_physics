# Performance

Single-threaded throughput of `tmuf_world_tick` on the Nations campaign map
**A01-Race** (Stadium, StadiumCar), measured with `tools/sim/tmuf_bench`
(commit fde7407, 2026-09-28).

## Results

| backend   | random inputs (ticks/s) | author replay (ticks/s)  | per tick (random) |
|-----------|-------------------------|--------------------------|-------------------|
| reference | **90 600**              | 45 300 (best run 46 900) | 11.0 µs           |
| optimized | **182 900**             | 90 600 (best run 94 600) | 5.5 µs            |

One tick is 10 ms of game time, so on one core the reference runs about
900× real time with random inputs (450× on the author's run), the optimized
backend about 1 800× (900×).

- Random inputs: five runs of 1 000 000 ticks (seeds 1–5), each an episode
  of 3 000 ticks (30 s, countdown included) from the start, restarted with
  `tmuf_world_copy` of the time-0 world. Inputs are held for 1–20 ticks:
  accelerate 80 %, brake 15 %, steering full left / full right / straight /
  analog. The five runs agree within 1 % (reference 90 100–91 000, optimized
  181 500–184 300 ticks/s).
- Author replay: the A01-Race.Replay.gbx shipped with the game (24.54 s,
  2 715 ticks), run 369 times; it finishes at the recorded time. It is
  slower per tick than random inputs: the car is fast, and the game splits
  a tick into more substeps the faster the car goes (3.3 per tick on
  average here, 1.04 with random inputs); each substep runs the whole
  collision detection.

Other costs (both backends):

| what                          | cost          |
|-------------------------------|---------------|
| `tmuf_world_copy` (same track) | 1.1 µs       |
| `sizeof(tmuf_world)`          | 19 888 bytes  |
| `tmuf_packs_open`             | 0.06–0.09 s   |
| `tmuf_track_load` (A01-Race)  | 0.25 s        |

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
`tools/sim/run_api_corpus.sh` on all 5 322 oracle replays that the game itself can simulate). The speed-up
comes from doing the same work with less overhead, not from different
arithmetic:

- all car trees walk the static tree and each reached mesh once, every
  cell tested against all trees at once (SSE/AVX; same operations as the
  game's box test), collisions then made in the reference's order;
- ellipsoid–triangle tests four triangles at a time (AVX: vertices and
  normal with the float operations per lane); a triangle is skipped without
  a root or division when a double-precision test shows, with a margin far
  above the float rounding error, that the float test finds no contact
  (86 % of the triangles on A01-Race; `-DTMUF_TRI_CHECK` runs the float
  test on every skipped triangle and aborts on a contact: none on the whole
  corpus);
- sin, cos, atan2, exp evaluate their series by Horner; a result within
  2^8 double ulps of a float rounding midpoint falls back to the
  reference's series, so the float results are the same
  (`tools/dev/fmath_check.sh` compares all 2^32 inputs);
- ellipsoid transforms built only when a triangle is reached; no debug
  hooks in the tick path; mesh cells read in place; single-precision
  `sqrtf` (provably the same result as the reference's double root
  rounded); the backend compiles as one unit (`unity.c`) so the small
  helpers inline across files.

Per tick (random inputs) the optimized backend spends about half its time
in collision detection (walks and triangles), the rest in car forces,
collision response and integration.

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
