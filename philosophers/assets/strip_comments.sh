#!/usr/bin/env bash
#
# copy_c_strip_inline_slashslash_only.sh
#
# Usage: ./copy_c_strip_inline_slashslash_only.sh SRC_DIR DEST_DIR
# Recursively copies all .c files from SRC_DIR to DEST_DIR (preserving
# directory structure) and removes only inline // comments that follow code.
# Lines that are only comments remain untouched. /* ... */ is not modified.

set -euo pipefail

if [[ $# -ne 2 ]]; then
    echo "Usage: $0 SRC_DIR DEST_DIR" >&2
    exit 1
fi

SRC_DIR=$1
DEST_DIR=$2

if [[ ! -d "$SRC_DIR" ]]; then
    echo "Source directory '$SRC_DIR' does not exist." >&2
    exit 1
fi

# Normalize to avoid trailing slash issues when computing relative paths
SRC_ROOT=${SRC_DIR%/}
DEST_ROOT=${DEST_DIR%/}

mkdir -p "$DEST_ROOT"

find "$SRC_ROOT" -type f -name '*.c' -print0 | while IFS= read -r -d '' src_file; do
    # Path relative to SRC_ROOT
    rel_path="${src_file#$SRC_ROOT/}"
    dest_file="$DEST_ROOT/$rel_path"

    mkdir -p "$(dirname "$dest_file")"

    # Remove // comments only if there is code before them on the same line
    perl -pe '
        # Match: [indent][code with at least one non-space] [optional spaces] // comment
        # Keep indent and code, drop the // comment
        s/^(\s*)(.*\S)\s*\/\/.*$/$1$2/;
    ' "$src_file" > "$dest_file"
done