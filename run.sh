#!/usr/bin/sh

# match all lines with conditional jumps, pass process output to python program for parsing

./analyze_branches \
    <(grep -E "([[:digit:]a-f]{4}):(\s+)(([[:digit:]a-f]{2}\s)+)\s*j" ${1} | grep -v "jmp")
