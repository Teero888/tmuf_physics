# tmnf_physics

TrackMania Nations/United Forever physics in C, aiming for bit-exact parity with
the original game (TmForever 2.11.26). It covers all seven United environments
and their vehicles.

The library contains two implementations of the same physics, selected at
compile time:

| Backend     | Directory        | Purpose                                     |
| ----------- | ---------------- | ------------------------------------------- |
| `reference` | `src/reference/` | Readable, follows the game's code structure |
| `optimized` | `src/optimized/` | Fast; must stay in parity with `reference`  |

The two backends never share a source file. Code both of them need (GBX, pack
and replay parsing into plain data) lives in `src/common/`.

The library has no global mutable state. Loaded assets are immutable and may be
shared between threads; each simulation owns its own context.

## Requirements

- A C11 compiler (GCC, Clang or MSVC), CMake 3.18+
- The `Packs` directory of a TrackMania United Forever installation. Nations
  Forever alone lacks the six non-Stadium environments.

## Build

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DTMNF_PHYSICS_BACKEND=reference
cmake --build build
ctest --test-dir build
```

Do not add `-ffast-math`, `/fp:fast` or FMA contraction: the physics depends on
exact IEEE single-precision results.

## Parity testing

- `tools/corpus/fetch_corpus.py` downloads replays from tmtas.exchange,
  tmnf.exchange and tmuf.exchange.
- `tools/oracle/` holds the state dumper that records per-tick vehicle state
  from the original game running under Wine, for tick-by-tick comparison.
