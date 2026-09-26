#!/usr/bin/env python3
"""Print paths of TMNF/TMUF (exever 2.11.x) replays under the given dirs.

tmtas.exchange also hosts TrackMania 2 replays, which the game rejects as
incompatible; this filters them out by the header XML.
"""
import os
import re
import sys

for root in sys.argv[1:]:
    for dirpath, _, files in os.walk(root):
        for name in sorted(files):
            if not name.endswith(".Replay.Gbx"):
                continue
            path = os.path.join(dirpath, name)
            with open(path, "rb") as f:
                head = f.read(8192)
            m = re.search(rb'exever="([^"]+)"', head)
            if m and m.group(1).startswith(b"2.11."):
                print(path)
