#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT="$SCRIPT_DIR/TrackCollisionExtractor/TrackCollisionExtractor.csproj"
OUTPUT="${1:-$SCRIPT_DIR/a01_collision.tmnfcol}"
MAP="$SCRIPT_DIR/../gbx_map/maps/White/A01-Race.Challenge.Gbx"
PACKS="$SCRIPT_DIR/../steamdata/Packs"

dotnet build "$PROJECT"

EXTRACTOR_DIR="$SCRIPT_DIR/TrackCollisionExtractor/bin/Debug/net8.0"
NATIVE_DIR="$EXTRACTOR_DIR/runtimes/linux-x64/native"
LOCAL_RUNTIME="$SCRIPT_DIR/dotnet/dotnet"
if [ -x "$LOCAL_RUNTIME" ]; then
    DOTNET_RUNTIME="$LOCAL_RUNTIME"
else
    DOTNET_RUNTIME="dotnet"
fi

LD_LIBRARY_PATH="$NATIVE_DIR${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}" \
    "$DOTNET_RUNTIME" "$EXTRACTOR_DIR/TrackCollisionExtractor.dll" \
    "$MAP" "$PACKS" "$OUTPUT"
