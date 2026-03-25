

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

/**
 * struct arguments - Command-line arguments passed to phaosfit.
 * @ratio: Aspect ratio string supplied by the user in W:H form.
 *
 * Store the parsed command-line arguments used by the program.
 */
struct arguments {
    char ratio[64];
};

#endif