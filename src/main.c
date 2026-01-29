#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include "arguments/arguments.h"

int main(int argc, char *argv[]) {
    int opt = 0;
    int long_index = 0;

    /*Default value(s)*/
    struct arguments arguments = {0};

    static struct option long_options[] = {
        {"ratio", required_argument, 0, 'r'},
        {0, 0, 0, 0}
    };

    // "r:" means: -r requires an argument.
    while ((opt = getopt_long(argc, argv, "r:", long_options, &long_index)) != -1) {
        switch (opt) {
            case 'r':
                // Store the ratio string in the 'arguments' struct.
                strncpy(arguments.ratio, optarg, sizeof(arguments.ratio) - 1);
                arguments.ratio[sizeof(arguments.ratio) - 1] = '\0';
                break;

            case '?':
            default:
                // Unknown option / missing argument.
                fprintf(stderr, "Usage: %s -r \"W:H\"  (or --ratio \"W:H\")\n", argv[0]);
                return 1;
        }
    }

    // For now: just print whatever was supplied.
    if (arguments.ratio[0] == '\0') {
        fprintf(stderr, "Missing required option: -r/--ratio\n");
        fprintf(stderr, "Usage: %s -r \"W:H\"  (or --ratio \"W:H\")\n", argv[0]);
        return 1;
    }

    printf("%s\n", arguments.ratio);

    return 0;
}
