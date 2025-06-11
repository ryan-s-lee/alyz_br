# Objdump Branch Partition Analyzer

## Method
1. Preprocess by grabbing only lines that contain conditional branches, using grep OR a real parser like tree-sitter-objdump
2. For each branch:
	1. Compute the address of the branch (highest address that contains a byte used to decode the instruction)
	2. Compute the 5th least significant bit of the address
	3. Update a frequency table tracking how often the PC[5] is a 1 or a 0
3. Print Frequency table, and print ratio normalized to total number of branches

## Usage:
The Makefile provides some tools for building and testing. Build with
```
make build
```

Execute with
```
./run.sh <input file>
```

Sample input files are contained in `in/`.
There is a `make test` rule, but it only runs `./run.sh` on one of the input files in `in/`.
