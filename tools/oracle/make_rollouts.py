#!/usr/bin/env python3
"""Random rollouts of existing replays, as replays the game's validator runs.

For each (replay, seed): the replay's inputs up to a random race time, then
random inputs (tools/sim tmuf_rollout). The game's validator compares the
car's position every 100 ms with the ghost's samples and stops the run
("Wrong Simu") when they differ, so the samples are rewritten from our own
simulation (tmuf_sim): the game then simulates the whole rollout as long as
it agrees with us, and run_oracle.py dumps it like any replay.

  make_rollouts.py --packs PACKS --build BUILD_DIR --out DIR --per N LIST
LIST: replay paths (one per line or "REPLAY ORACLE VERDICT" lines).
"""
import argparse, os, random, struct, subprocess, sys, zlib


def samples_load(data, off):
    size, psize = struct.unpack_from('<II', data, off)
    raw = zlib.decompress(bytes(data[off + 8:off + 8 + psize]))
    p = 20
    blen, = struct.unpack_from('<I', raw, p); p += 4
    buf = raw[p:p + blen]; p += blen
    n, = struct.unpack_from('<i', raw, p); p += 4
    first = size1 = None; sizes = None
    if n > 0:
        first, = struct.unpack_from('<i', raw, p); p += 4
        if n > 1:
            size1, = struct.unpack_from('<i', raw, p); p += 4
            if size1 == -1:
                sizes = list(struct.unpack_from('<%di' % (n - 1), raw, p)); p += 4 * (n - 1)
    return dict(head=raw[:20], buf=buf, n=n, first=first, size=size1, sizes=sizes, tail=raw[p:], psize=psize)


def sample_bytes(s, i):
    if s['size'] not in (None, -1):
        o = s['first'] + i * s['size']
        return s['buf'][o:o + s['size']]
    o = s['first'] + sum(s['sizes'][:i])
    z = s['sizes'][i] if i < s['n'] - 1 else len(s['buf']) - o
    return s['buf'][o:o + z]


def rewrite(path, off, positions, end_ms):
    """ghost samples with our positions (sample i: the car at 2590 + 100 i ms)"""
    data = bytearray(open(path, 'rb').read())
    s = samples_load(data, off)
    if s['n'] < 2 or s['size'] in (None, -1):
        return False
    tmpl = sample_bytes(s, 0)
    n = (end_ms - 2590) // 100 + 1 + 30  # the game records ~3 s past the end
    last = max(positions)
    buf = bytearray()
    for i in range(n):
        t = 2590 + 100 * i
        x, y, z = positions.get(t if t <= last else last)
        buf += struct.pack('<3f', x, y, z) + tmpl[12:]
    raw = s['head'] + struct.pack('<I', len(buf)) + bytes(buf) + struct.pack('<iii', n, 0, len(tmpl)) + s['tail']
    c = zlib.compress(raw, 9)
    out = data[:off] + struct.pack('<II', len(raw), len(c)) + c + data[off + 8 + s['psize']:]
    open(path, 'wb').write(out)
    return True


def f32(v):
    return struct.unpack('<f', struct.pack('<f', float(v)))[0]


def positions_of(tmuf_sim, packs, replay):
    """the car's position the game samples at each tick time t: the end of
    tick t, or the respawn location when tick t + 10 respawns (the sample is
    taken after the next tick's respawn is applied, before its physics)"""
    out = subprocess.run([tmuf_sim, packs, replay, '--print'], capture_output=True, text=True,
                         errors='replace').stdout
    end, spawn, resp = {}, {}, {}
    for l in out.splitlines():
        if not l.startswith('t='):
            continue
        p = l.split()
        t = int(p[0][2:])
        end[t] = tuple(f32(v) for v in p[2:5])
        i = p.index('resp')
        resp[t] = int(p[i + 1])
        spawn[t] = tuple(f32(v) for v in p[i + 3:i + 6])
    return {t: (spawn[t] if resp.get(t + 10) else end[t]) for t in end}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--packs', required=True)
    ap.add_argument('--build', required=True, help='reference build with tmuf_sim and tmuf_rollout')
    ap.add_argument('--out', required=True)
    ap.add_argument('--per', type=int, default=1, help='rollouts per replay')
    ap.add_argument('--seed', type=int, default=1)
    ap.add_argument('list')
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    roll = os.path.join(a.build, 'tmuf_rollout'); sim = os.path.join(a.build, 'tmuf_sim')
    rng = random.Random(a.seed)
    for line in open(a.list):
        if not line.strip():
            continue
        src = line.split()[0]
        stem = os.path.basename(src).split('.')[0]
        for k in range(a.per):
            seed = rng.randrange(1, 1 << 30)
            dst = os.path.join(a.out, '%s_r%d.Replay.Gbx' % (stem, seed))
            if os.path.exists(dst):
                continue
            r = subprocess.run([roll, src, dst, str(seed)], capture_output=True, text=True, errors='replace')
            if r.returncode:
                print(stem, 'skip:', r.stderr.strip()); break
            frm, length, nev = map(int, r.stdout.split())
            off = int(subprocess.run([roll, dst, dst + '.tmp', '--plain'], capture_output=True, text=True,
                                     errors='replace').stdout)
            os.remove(dst + '.tmp')
            pos = positions_of(sim, a.packs, dst)
            if not pos or not rewrite(dst, off, pos, 2600 + frm + length):
                print(stem, 'skip: samples'); os.remove(dst); break
            print(os.path.basename(dst), frm, length, nev, flush=True)


if __name__ == '__main__':
    main()
