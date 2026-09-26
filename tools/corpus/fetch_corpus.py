#!/usr/bin/env python3
"""Download a replay corpus for parity testing.

Sources:
  tmtas  - tmtas.exchange, every tool-assisted replay (documented public API)
  tmnf   - tmnf.exchange, world-record replay of recent tracks (Stadium)
  tmuf   - tmuf.exchange, world-record replays, balanced across environments

Resumable: existing files are skipped and a manifest.jsonl per source records
what was fetched. Requests are throttled; be nice to the exchanges.

  fetch_corpus.py OUT_DIR [--source tmtas|tmnf|tmuf|all] [--limit N]
"""
import argparse
import json
import os
import sys
import time
import urllib.error
import urllib.request

USER_AGENT = "tmuf_physics-corpus/0.1 (+https://github.com/Teero888)"
DELAY = 1.0


def get(url, tries=4):
    for attempt in range(tries):
        try:
            req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
            with urllib.request.urlopen(req, timeout=60) as resp:
                data = resp.read()
            time.sleep(DELAY)
            return data
        except urllib.error.HTTPError as e:
            if e.code in (404, 410):
                time.sleep(DELAY)
                return None
            wait = 30 * (attempt + 1) if e.code == 429 else 5 * (attempt + 1)
            print(f"  HTTP {e.code} for {url}, retry in {wait}s", file=sys.stderr)
            time.sleep(wait)
        except (urllib.error.URLError, TimeoutError, ConnectionError) as e:
            print(f"  {e} for {url}, retry", file=sys.stderr)
            time.sleep(5 * (attempt + 1))
    return None


def get_json(url):
    data = get(url)
    return json.loads(data) if data else None


class Sink:
    def __init__(self, out_dir, source):
        self.dir = os.path.join(out_dir, source)
        os.makedirs(self.dir, exist_ok=True)
        self.manifest = open(os.path.join(self.dir, "manifest.jsonl"), "a")

    def path(self, name):
        return os.path.join(self.dir, name)

    def save(self, name, url, meta):
        p = self.path(name)
        if os.path.exists(p):
            return False
        data = get(url)
        if not data or not data.startswith(b"GBX"):
            print(f"  skip {name}: not a GBX", file=sys.stderr)
            return False
        tmp = p + ".part"
        with open(tmp, "wb") as f:
            f.write(data)
        os.replace(tmp, p)
        self.manifest.write(json.dumps({"file": name, "url": url, **meta}) + "\n")
        self.manifest.flush()
        return True


def fetch_tmtas(out_dir, limit):
    sink = Sink(out_dir, "tmtas")
    seen, count, max_date = set(), 0, None
    while count < limit:
        url = "https://tmtas.exchange/api/replays?minDate=0"
        if max_date is not None:
            url += f"&maxDate={max_date}"
        page = get_json(url)
        new = [r for r in (page or []) if r["id"] not in seen]
        if not new:
            break
        for r in new:
            seen.add(r["id"])
            if count >= limit:
                break
            name = f"{r['id']}.Replay.Gbx"
            if sink.save(name, f"https://tmtas.exchange/api/replay?id={r['id']}", r):
                print(f"tmtas {r['id']} ({r['time']} ms, {r['author']})")
            count += 1
        # Newest first; step below the oldest date on this page. Keep the
        # boundary second itself in range, `seen` drops the duplicates.
        max_date = min(r["date"] for r in new)
        if len(new) < 2:
            max_date -= 1


def fetch_tmx(out_dir, site, limit, environments):
    sink = Sink(out_dir, site)
    per_env = max(1, limit // len(environments))
    for env in environments:
        after, got = None, 0
        while got < per_env:
            url = (f"https://{site}.exchange/api/tracks?fields=TrackId,TrackName,Environment,"
                   f"WRReplay.ReplayId,WRReplay.ReplayTime&count=100&inhasrecord=1")
            if env is not None:
                url += f"&environment={env}"
            if after is not None:
                url += f"&after={after}"
            page = get_json(url)
            if not page or not page.get("Results"):
                break
            for t in page["Results"]:
                after = t["TrackId"]
                wr = t.get("WRReplay") or {}
                rid = wr.get("ReplayId")
                if not rid or got >= per_env:
                    continue
                name = f"{rid}.Replay.Gbx"
                meta = {"track_id": t["TrackId"], "track": t["TrackName"],
                        "environment": t["Environment"], "time": wr.get("ReplayTime")}
                if sink.save(name, f"https://{site}.exchange/recordgbx/{rid}", meta):
                    print(f"{site} env{t['Environment']} {rid} ({meta['time']} ms) {t['TrackName']}")
                got += 1
            if not page.get("More"):
                break


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("out_dir")
    ap.add_argument("--source", default="all", choices=["tmtas", "tmnf", "tmuf", "all"])
    ap.add_argument("--limit", type=int, default=None, help="max replays per source")
    args = ap.parse_args()

    if args.source in ("tmtas", "all"):
        fetch_tmtas(args.out_dir, args.limit or 10**9)
    if args.source in ("tmnf", "all"):
        fetch_tmx(args.out_dir, "tmnf", args.limit or 1500, [None])
    if args.source in ("tmuf", "all"):
        # The filter is 0-based; the six non-Stadium environments plus Stadium.
        fetch_tmx(args.out_dir, "tmuf", args.limit or 2100, list(range(7)))


if __name__ == "__main__":
    main()
