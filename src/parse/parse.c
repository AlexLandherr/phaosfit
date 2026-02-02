#include "parse.h"
#include "../formats/aspect_ratio.h"
#include <regex.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct aspect_ratio parse_aspect_ratio(char *ratio_str) {
    struct aspect_ratio ar = {0};

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