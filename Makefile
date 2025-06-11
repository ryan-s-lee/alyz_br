.PHONY: dbuild build test

build: analyze_branches

analyze_branches: src/main.c
	gcc -o analyze_branches $^

test: analyze_branches
	bash run.sh in/505_mcf_r_objdump.txt
