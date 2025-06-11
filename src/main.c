#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \t\r\n"

void printResults(unsigned long* freqs) {
    printf("Results:\n");
    printf("Partition 0: %lu\n", freqs[0]);
    printf("Partition 1: %lu\n", freqs[1]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect usage\n");
        printf("Usage: %s <input-file>\n", argv[0]);
    }

    unsigned long freqs[2] = {0, 0};
    FILE *inf = fopen(argv[1], "r");

    char *fline = NULL;
    size_t buflen = 0;
    size_t fline_len = 0;

    // for each line in the file,
    while ((fline_len = getline(&fline, &buflen, inf)) != -1) {
        // extract instruction start address from first token
        char *token = strtok(fline, DELIMS);
        assert(token != NULL);
        unsigned long long pc = strtoll(token, NULL, 16);
        if (pc == 0) {
            printf("Failed at token: %s, line: %s", token, fline);
            fflush(stdout);
            assert(pc != 0);  // legally PCs can never be 0
        }

        // count byte length of instruction
        int instr_length = 0;
        while ((token = strtok(NULL, DELIMS)) != NULL && token[0] != 'j') {
            instr_length += 1;
        }
        assert (instr_length > 0);
        assert (token[0] == 'j');

        pc += instr_length - 1;
        int pc5 = pc & 0b10000;
        int partition = pc5 ? 1 : 0;
        freqs[partition] += 1;

        free(fline);
        fline = NULL;
    }

    if (!feof(inf)) {
        perror("Failed, perror");
    }

    printResults(freqs);
}
