#!/bin/sh
# run_api_corpus.sh LIST OUTDIR [JOBS]: tmuf_api_check (public API, world
# copies) over LIST split into JOBS parts; the parity test for any backend
set -e
LIST=$1; OUT=$2; JOBS=${3:-6}
BIN=${TMUF_API_CHECK:-$(dirname "$0")/../../build-rel/tmuf_api_check}
PACKS=${TMUF_PACKS:-"$HOME/.local/share/Steam/steamapps/common/TrackMania United/Packs"}
mkdir -p "$OUT"
rm -f "$OUT"/part.* "$OUT"/out.*
split -n r/$JOBS -d "$LIST" "$OUT/part."
for p in "$OUT"/part.*; do
  "$BIN" "$PACKS" "$p" > "$OUT/out.${p##*.}" 2>/dev/null &
done
wait
cat "$OUT"/out.* | grep -E " MATCH | DIVERGE | ERROR " | sort > "$OUT/all.txt"
awk '{print $2}' "$OUT/all.txt" | sort | uniq -c
