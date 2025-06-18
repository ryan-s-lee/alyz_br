.PHONY: dbuild build test alyz_freq_dyn

build: analyze_branches

analyze_branches: src/main.c
	gcc -o analyze_branches $^

test: analyze_branches
	bash run.sh in/505_mcf_r_objdump.txt

alyz_freq_dyn:
	bash scripts/runspec.sh
	perf script -F brstack 1> dump.txt 2>&1
	python scripts/brinstr_freq.py ./dump.txt

parse_dump:
	python scripts/brinstr_freq.py ./dump.txt
