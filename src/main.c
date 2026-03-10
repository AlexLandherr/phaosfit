#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "formats/aspect_ratio.h"
#include "arguments/arguments.h"
#include "validation/validation.h"
#include "parse/parse.h"

int main(int argc, char *argv[]) {
    int opt = 0;
    int long_index = 0;

    /*Default value(s)*/
    struct arguments arguments = {0};

    static struct option long_options[] = {
        {"ratio", required_argument, 0, 'r'},
        {0, 0, 0, 0}
    };

    //"r:" means: -r requires an argument.
    while ((opt = getopt_long(argc, argv, "r:", long_options, &long_index)) != -1) {
        switch (opt) {
            case 'r':
                //Store the ratio string in the 'arguments' struct.
                strncpy(arguments.ratio, optarg, sizeof(arguments.ratio) - 1);
                arguments.ratio[sizeof(arguments.ratio) - 1] = '\0';
                break;

            case '?':
            default:
                //Unknown option / missing argument.
                fprintf(stderr, "Usage: %s -r \"W:H\"  (or --ratio \"W:H\")\n", argv[0]);
                return 1;
        }
    }

    //For now: just print whatever was supplied.
    if (arguments.ratio[0] == '\0') {
        fprintf(stderr, "Missing required option: -r/--ratio\n");
        fprintf(stderr, "Usage: %s -r \"W:H\"  (or --ratio \"W:H\")\n", argv[0]);
        return 1;
    }

    //Validity check of ratio string.
    if (!is_valid_ratio_str(arguments.ratio)) {
        fprintf(stderr, "Invalid ratio string: '%s'\n", arguments.ratio);
        return 1;
    }
    //Using arguments.ratio by printing it to stdout.
    printf("Passed value: '%s'\n", arguments.ratio);

    //Check if W is a decimal/floating-point value.
    if (W_is_float_str(arguments.ratio)) {
        printf("W is a floating-point value!\n");
        struct aspect_ratio_decimal ar_float = parse_aspect_ratio_decimal(arguments.ratio);
        printf("W: %.15f, H: %ld\n", ar_float.w, ar_float.h);
    } else {
        printf("W is an integer value!\n");
        struct aspect_ratio_integer ar_int = parse_aspect_ratio_integer(arguments.ratio);
        printf("W: %ld, H: %ld\n", ar_int.w, ar_int.h);
    }

    return 0;
}
