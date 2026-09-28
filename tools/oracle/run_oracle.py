#!/usr/bin/env python3
"""Run replays through the real game with dumper.dll and collect per-tick dumps.

Each worker owns a headless Xvfb display and a private copy of the Wine
prefix, and validates one replay per game launch (/validatepath). The
"Account Connection" dialog shown at startup is dismissed with Escape, which
keeps the game offline.

  run_oracle.py --template-prefix PFX --game DIR --out OUT [--workers N] REPLAY...

Per replay, OUT gets <stem>.tmor.gz (the dump) and a line in results.jsonl
with the game's verdict. Replays already listed in results.jsonl are skipped.
"""
import argparse
import gzip
import json
import os
import queue
import re
import shutil
import subprocess
import sys
import threading
import time

HERE = os.path.dirname(os.path.abspath(__file__))
BUILD = os.path.join(HERE, "build")
WIDTH, HEIGHT = 800, 600
PROFILE = "steamuser"
REPLAY_SUBDIR = "oracle"

# "Account Connection" title bar, as fractions of the screen (clear of the
# title text), and its colour.
DIALOG_PIXELS = [(0.25, 0.332), (0.33, 0.332), (0.67, 0.332), (0.75, 0.332)]
DIALOG_RGB = (0x1a, 0x4e, 0x93)

VERDICTS = ["Can't load", "Incompatibl", "Is Invalid", "Is Valid", "Wrong Simu", "Is Puzzle"]


def to_windows_path(path):
    return "Z:" + os.path.abspath(path).replace("/", "\\")


class Worker:
    def __init__(self, index, args):
        self.index = index
        self.args = args
        self.display = f":{args.display_base + index}"
        self.root = os.path.join(args.out, "workers", str(index))
        self.prefix = os.path.join(self.root, "pfx")
        self.docs = os.path.join(self.prefix, "drive_c", "users", os.environ.get("USER", "user"),
                                 "Documents", "TrackMania")
        self.xvfb = None

    def env(self):
        env = dict(os.environ)
        env.update(DISPLAY=self.display, WINEPREFIX=self.prefix, WINEDEBUG="-all")
        return env

    def setup(self):
        if not os.path.isdir(self.prefix):
            os.makedirs(self.root, exist_ok=True)
            shutil.copytree(self.args.template_prefix, self.prefix, symlinks=True)
        self.start_xvfb()

    def start_xvfb(self):
        self.xvfb = subprocess.Popen(
            ["Xvfb", self.display, "-screen", "0", f"{WIDTH}x{HEIGHT}x24", "-nolisten", "tcp"],
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        time.sleep(1)

    def teardown(self):
        subprocess.run(["wineserver", "-k"], env=self.env(), stderr=subprocess.DEVNULL)
        if self.xvfb:
            self.xvfb.terminate()
        if not self.args.keep_prefixes:
            # Each prefix copy is ~700 MB.
            shutil.rmtree(self.root, ignore_errors=True)

    def pixel(self, fx, fy):
        x, y = int(fx * WIDTH), int(fy * HEIGHT)
        out = subprocess.run(["import", "-window", "root", "-crop", f"1x1+{x}+{y}", "-depth", "8", "txt:-"],
                             env=self.env(), capture_output=True, text=True).stdout
        m = re.search(r"#([0-9A-Fa-f]{6})", out)
        return tuple(int(m.group(1)[i:i + 2], 16) for i in (0, 2, 4)) if m else None

    def dialog_visible(self):
        for fx, fy in DIALOG_PIXELS:
            px = self.pixel(fx, fy)
            if px is None or any(abs(a - b) > 24 for a, b in zip(px, DIALOG_RGB)):
                return False
        return True

    def press_escape(self):
        ids = subprocess.run(["xdotool", "search", "--name", "TrackMania"], env=self.env(),
                             capture_output=True, text=True).stdout.split()
        for wid in ids:
            subprocess.run(["xdotool", "key", "--window", wid, "Escape"], env=self.env(),
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    def screenshot(self, path):
        subprocess.run(["import", "-window", "root", path], env=self.env(), stderr=subprocess.DEVNULL)

    def run(self, replay):
        if self.xvfb is None or self.xvfb.poll() is not None:
            self.start_xvfb()
        stem = os.path.basename(replay)[:-len(".Replay.Gbx")]
        replay_dir = os.path.join(self.docs, "Tracks", "Replays", REPLAY_SUBDIR)
        shutil.rmtree(replay_dir, ignore_errors=True)
        os.makedirs(replay_dir)
        shutil.copy(replay, os.path.join(replay_dir, os.path.basename(replay)))
        log_path = os.path.join(self.docs, "ValidateLog.txt")
        if os.path.exists(log_path):
            os.remove(log_path)
        dump = os.path.join(self.root, "dump.bin")
        if os.path.exists(dump):
            os.remove(dump)

        env = self.env()
        env["TMUF_ORACLE_OUT"] = to_windows_path(dump)
        if self.args.trace:
            env["TMUF_ORACLE_TRACE"] = self.args.trace
        start = time.time()
        proc = subprocess.Popen(
            ["wine", os.path.join(self.args.build, "launcher.exe"), os.path.join(self.args.build, "dumper.dll"),
             "TmForever.exe", f"/profile={PROFILE}", f"/validatepath={REPLAY_SUBDIR}\\"],
            cwd=self.args.game, env=env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        dismissed = 0
        timed_out = False
        while proc.poll() is None:
            if time.time() - start > self.args.timeout:
                timed_out = True
                self.screenshot(os.path.join(self.args.out, "timeouts", stem + ".png"))
                subprocess.run(["wineserver", "-k"], env=self.env(), stderr=subprocess.DEVNULL)
                proc.wait()
                break
            if dismissed < 3 and self.dialog_visible():
                self.press_escape()
                dismissed += 1
                time.sleep(2)
            time.sleep(1)
        subprocess.run(["wineserver", "-w"], env=self.env(), timeout=60)

        result = {"replay": replay, "stem": stem, "seconds": round(time.time() - start, 1),
                  "worker": self.index, "timed_out": timed_out}
        if os.path.exists(log_path):
            text = open(log_path, errors="replace").read()
            for v in VERDICTS:
                m = re.search(re.escape(v) + r"\s*:\s*\d+% \(\s*(\d+)\)", text)
                if m and int(m.group(1)) > 0:
                    result["verdict"] = v.strip()
            result["log"] = text
        else:
            result["verdict"] = None
        if os.path.exists(dump) and os.path.getsize(dump) > 12:
            out = os.path.join(self.args.out, "dumps", stem + ".tmor.gz")
            with open(dump, "rb") as src, gzip.open(out, "wb", compresslevel=6) as dst:
                shutil.copyfileobj(src, dst)
            result["dump"] = out
        if os.path.exists(dump + ".plain"):
            out = os.path.join(self.args.out, "dumps", stem + ".plain.gz")
            with open(dump + ".plain", "rb") as src, gzip.open(out, "wb", compresslevel=3) as dst:
                shutil.copyfileobj(src, dst)
            os.remove(dump + ".plain")
            result["plain"] = out
        if os.path.exists(dump + ".cells"):
            out = os.path.join(self.args.out, "dumps", stem + ".cells.gz")
            with open(dump + ".cells", "rb") as src, gzip.open(out, "wb", compresslevel=6) as dst:
                shutil.copyfileobj(src, dst)
            os.remove(dump + ".cells")
        if os.path.exists(dump + ".trace"):
            out = os.path.join(self.args.out, "dumps", stem + ".trace.gz")
            with open(dump + ".trace", "rb") as src, gzip.open(out, "wb", compresslevel=6) as dst:
                shutil.copyfileobj(src, dst)
            os.remove(dump + ".trace")
            result["trace"] = out
        return result


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--template-prefix", required=True)
    ap.add_argument("--game", required=True, help="game directory containing TmForever.exe")
    ap.add_argument("--out", required=True)
    ap.add_argument("--workers", type=int, default=4)
    ap.add_argument("--timeout", type=float, default=600)
    ap.add_argument("--build", default=BUILD, help="directory with launcher.exe and dumper.dll")
    ap.add_argument("--trace", default="", help="TMUF_ORACLE_TRACE for the dumper, e.g. feedback")
    ap.add_argument("--display-base", type=int, default=90, help="worker i uses X display :BASE+i")
    ap.add_argument("--keep-prefixes", action="store_true", help="keep worker Wine prefixes after the run")
    ap.add_argument("replays", nargs="+")
    args = ap.parse_args()
    # Wine runs from the game directory; make every path absolute.
    args.build = os.path.abspath(args.build)
    args.out = os.path.abspath(args.out)
    args.game = os.path.abspath(args.game)
    args.template_prefix = os.path.abspath(args.template_prefix)

    for d in ("dumps", "timeouts", "workers"):
        os.makedirs(os.path.join(args.out, d), exist_ok=True)
    results_path = os.path.join(args.out, "results.jsonl")
    done = set()
    if os.path.exists(results_path):
        for line in open(results_path):
            r = json.loads(line)
            # Runs without a verdict (game never finished) are retried.
            if r.get("verdict"):
                done.add(r["replay"])

    todo = queue.Queue()
    for r in args.replays:
        if r.endswith(".Replay.Gbx") and os.path.abspath(r) not in done:
            todo.put(os.path.abspath(r))
    total = todo.qsize()
    print(f"{total} replays to run, {len(done)} already done", flush=True)

    lock = threading.Lock()
    results = open(results_path, "a")
    counter = [0]

    def work(index):
        w = Worker(index, args)
        w.setup()
        try:
            while True:
                try:
                    replay = todo.get_nowait()
                except queue.Empty:
                    return
                try:
                    res = w.run(replay)
                except Exception as e:  # keep the batch going
                    res = {"replay": replay, "error": repr(e), "worker": index}
                with lock:
                    counter[0] += 1
                    results.write(json.dumps(res) + "\n")
                    results.flush()
                    print(f"[{counter[0]}/{total}] w{index} {os.path.basename(replay)}: "
                          f"{res.get('verdict')} {res.get('seconds')}s"
                          f"{' TIMEOUT' if res.get('timed_out') else ''}{' ERR ' + res['error'] if 'error' in res else ''}",
                          flush=True)
        finally:
            w.teardown()

    threads = [threading.Thread(target=work, args=(i,)) for i in range(args.workers)]
    for t in threads:
        t.start()
    for t in threads:
        t.join()


if __name__ == "__main__":
    sys.exit(main())
