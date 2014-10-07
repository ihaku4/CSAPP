#! /bin/sh

ls *.note | while read FNAME; do echo "\n\n############\n$FNAME\n############\n"; cat "$FNAME"; done | less
