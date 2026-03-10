#include "../formats/aspect_ratio.h"
#include <stdbool.h>

#ifndef PARSE_H
#define PARSE_H

bool W_is_float_str(char *ratio_str);

struct aspect_ratio_decimal parse_aspect_ratio_decimal(char *ratio_str);

struct aspect_ratio_integer parse_aspect_ratio_integer(char *ratio_str);

#endif