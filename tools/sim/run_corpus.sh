#!/bin/sh
# run_corpus.sh LIST OUTDIR [JOBS]: tmuf_sim --batch over LIST split into JOBS parts
set -e
LIST=$1; OUT=$2; JOBS=${3:-8}
BIN=${TMUF_SIM:-$(dirname "$0")/../../build-rel/tmuf_sim}
PACKS=${TMUF_PACKS:-"$HOME/.local/share/Steam/steamapps/common/TrackMania United/Packs"}
mkdir -p "$OUT"
rm -f "$OUT"/part.* "$OUT"/out.*
split -n r/$JOBS -d "$LIST" "$OUT/part."
for p in "$OUT"/part.*; do
  "$BIN" "$PACKS" --batch "$p" > "$OUT/out.${p##*.}" 2>/dev/null &
done
wait
cat "$OUT"/out.* | grep -E "MATCH|DIVERGE|ERROR" | sort > "$OUT/all.txt"
awk '{print $2}' "$OUT/all.txt" | sort | uniq -c
