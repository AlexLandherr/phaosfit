#include <stdbool.h>

#ifndef VALIDATION_H
#define VALIDATION_H

#define RATIO_PATTERN "^([1-9][0-9]*)(\\.[0-9]{0,15})?:([1-9][0-9]*)$"

bool is_valid_ratio_str(char *ratio_str);

#endif