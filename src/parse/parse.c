#include "parse.h"
#include "../formats/aspect_ratio.h"
#include <regex.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool W_is_float_str(char *ratio_str) {
    const char *decimal_sign = strchr(ratio_str, '.');
    return decimal_sign == NULL ? false : true;
}

/*
Parse aspect ratio when W is a decimal value/floating point value,
e.g. "1.85:1" or "2.39:1" etc.
*/
struct aspect_ratio_decimal parse_aspect_ratio_decimal(char *ratio_str) {
    struct aspect_ratio_decimal ar = {0};

    const char *colon = strchr(ratio_str, ':');   //ratio_str is known-valid "W:H".
    size_t w_len = (size_t)(colon - ratio_str);

    //Copy W part into a temp buffer (so strtod gets a null-terminated string).
    char w_buf[64];
    memcpy(w_buf, ratio_str, w_len);
    w_buf[w_len] = '\0';

    ar.w = strtod(w_buf, NULL);
    ar.h = strtol(colon + 1, NULL, 10);

    return ar;
}

/*
Parse aspect ratio when W is a integer value,
e.g. "16:9" or "4:3" etc.
*/
struct aspect_ratio_integer parse_aspect_ratio_integer(char *ratio_str) {
    struct aspect_ratio_integer ar = {0};

    const char *colon = strchr(ratio_str, ':');   //ratio_str is known-valid "W:H".
    size_t w_len = (size_t)(colon - ratio_str);

    //Copy W part into a temp buffer (so strtod gets a null-terminated string).
    char w_buf[64];
    memcpy(w_buf, ratio_str, w_len);
    w_buf[w_len] = '\0';

    ar.w = strtol(w_buf, NULL, 10);
    ar.h = strtol(colon + 1, NULL, 10);

    return ar;
}