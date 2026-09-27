#!/usr/bin/env python3
"""Compare the car's contacts per tick: an oracle physics trace (dumper with
TMUF_ORACLE_TRACE=physics) against tmuf_sim's TMUF_SIM_TRACE output.

usage: cmp_contacts.py ORACLE.tmor.gz SIM_TRACE.txt [--context N]

Prints the first tick whose contact list differs (count, normal, point,
speed, replacement or peer material) with both lists."""
import gzip, re, struct, sys


def read_oracle(path):
    d = gzip.open(path).read()
    assert d[:4] == b'TMOR'
    size = struct.unpack_from('<I', d, 8)[0]
    p = 12
    steps = []
    cur = {'step': -1, 'con': [], 'end': False}
    while p < len(d):
        t = d[p]
        p += 1
        if t == 1:
            idx, _ = struct.unpack_from('<II', d, p)
            p += 8
            cur = {'step': idx, 'con': [], 'end': False}
            steps.append(cur)
        elif t == 2:
            p += 4 + size
            cur['end'] = True
        elif t in (3, 5):
            p += (8 if t == 3 else 4) + size
        elif t == 4:
            p += 4
            raw = d[p:p + 0x60]
            p += 0x60
            f = struct.unpack_from('<24f', raw)
            w = struct.unpack_from('<24I', raw)
            cur['con'].append((f[3:6], f[6:9], f[9:12], f[12:15], w[18] & 0xffff))
        else:
            raise ValueError('bad record %d at %d' % (t, p))
    # PhysicsStep2 runs twice per tick; the car's step is the one that ends
    return [s['con'] for s in steps if s['end']]


TOL = float(__import__("os").environ.get("CMP_TOL", "1e-6"))

LINE = re.compile(r'CON t=(\d+) w(-?\d+) n (\S+) (\S+) (\S+) p (\S+) (\S+) (\S+) v (\S+) (\S+) (\S+) '
                  r'r (\S+) (\S+) (\S+) mat (\d+)')


def read_sim(path):
    ticks = {}
    for line in open(path):
        m = LINE.search(line)
        if not m:
            continue
        g = m.groups()
        f = [float(x) for x in g[2:14]]
        tick = int(g[0]) // 10 - 1
        ticks.setdefault(tick, []).append((tuple(f[0:3]), tuple(f[3:6]), tuple(f[6:9]), tuple(f[9:12]), int(g[14])))
    return ticks


def close(a, b):
    return all(abs(x - y) <= TOL * max(1.0, abs(x), abs(y)) for x, y in zip(a, b))


def same(ca, cb):
    return len(ca) == len(cb) and all(
        all(close(x[k], y[k]) for k in range(4)) and x[4] == y[4] for x, y in zip(ca, cb))


def fmt(c):
    return 'n(%.5g %.5g %.5g) p(%.5g %.5g %.5g) v(%.5g %.5g %.5g) r(%.4g %.4g %.4g) mat %d' % (
        *c[0], *c[1], *c[2], *c[3], c[4])


def main():
    oracle = read_oracle(sys.argv[1])
    sim = read_sim(sys.argv[2])
    last = max(sim) if sim else -1
    for tick in range(min(len(oracle), last + 1)):
        a = oracle[tick]
        b = sim.get(tick, [])
        if same(a, b):
            continue
        print('tick %d: oracle %d contacts, ours %d' % (tick, len(a), len(b)))
        for c in a:
            print('  oracle', fmt(c))
        for c in b:
            print('  ours  ', fmt(c))
        return 1
    print('contacts match through tick %d' % last)
    return 0


if __name__ == '__main__':
    sys.exit(main())
