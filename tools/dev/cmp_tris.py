#!/usr/bin/env python3
"""Compare two static triangle dumps (u32 count, 9 f32 per triangle).
Reports exact matches (bitwise, any vertex rotation), near matches, and
where the unmatched triangles are (in 32x8x32 cells)."""
import collections, struct, sys

def load(path):
    d = open(path, 'rb').read()
    n = struct.unpack_from('<I', d)[0]
    raw = [d[4 + i * 36: 40 + i * 36] for i in range(n)]
    fl = [struct.unpack('<9f', r) for r in raw]
    return raw, fl

def canon_raw(r):
    v = [r[0:12], r[12:24], r[24:36]]
    k = min(range(3), key=lambda i: v[i])
    return b''.join(v[k:] + v[:k])

def canon_q(f, q):
    v = [tuple(round(x / q) for x in f[i * 3:i * 3 + 3]) for i in range(3)]
    k = min(range(3), key=lambda i: v[i])
    return tuple(v[k:] + v[:k])

def main():
    a_raw, a = load(sys.argv[1])
    b_raw, b = load(sys.argv[2])
    q = float(sys.argv[3]) if len(sys.argv) > 3 else 1e-3
    print(f'A {len(a)} B {len(b)}')
    ca = collections.Counter(canon_raw(r) for r in a_raw)
    cb = collections.Counter(canon_raw(r) for r in b_raw)
    exact = sum((ca & cb).values())
    print(f'exact matches {exact}')
    qa = collections.Counter(canon_q(f, q) for f in a)
    qb = collections.Counter(canon_q(f, q) for f in b)
    near = sum((qa & qb).values())
    print(f'near matches (q={q}) {near}')
    onlya = qa - qb
    onlyb = qb - qa
    def cells(c):
        cc = collections.Counter()
        for k, n in c.items():
            x, y, z = (k[0][i] * q for i in range(3))
            cc[(int(x // 32), int(y // 8), int(z // 32))] += n
        return cc
    for name, c in (('only A', onlya), ('only B', onlyb)):
        cc = cells(c)
        print(f'{name}: {sum(c.values())} in {len(cc)} cells; top:', cc.most_common(25))

main()
