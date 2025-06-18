#!/usr/bin/sh
taskset -c 0,0 perf record -b -e cycles,instructions,br_inst_retired.cond:pp,br_misp_retired.cond:pp runcpu -d --config=/home/ryan/cpu2017/config/RapModConfig-llvm.cfg --action=onlyrun --size=ref --copies=1 --noreportable --iterations=1 505.mcf_r
