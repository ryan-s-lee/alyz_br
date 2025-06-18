#!/usr/bin/sh

grep -E "([[:digit:]a-f]{4}):(\s+)(([[:digit:]a-f]{2}\s)+)\s*j" ${1} | grep -v "jmp"
