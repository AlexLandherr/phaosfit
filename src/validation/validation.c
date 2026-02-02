#include "validation.h"
#include <regex.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool is_valid_ratio_str(char *ratio_str) {
    regex_t re;
    regmatch_t m[4]; //0 = whole match, 1 = W is an int, 2 = W is a frac (optional), 3 = H
    int rc;

    //1. Compiling the pattern.
    rc = regcomp(&re, RATIO_PATTERN, REG_EXTENDED);
    if (rc != 0) {
        return false;
    }

    //2. Matching with given string.
    rc = regexec(&re, ratio_str, 4, m, 0);
    if (rc != 0) {
        regfree(&re);
        return false;
    }

    //3. Extract W (group 1 + optional group 2) into w_buf.
    char w_buf[64];
    size_t w_len = 0;

    //group 1.
    int w1_start = m[1].rm_so;
    int w1_end   = m[1].rm_eo;
    size_t w1_len = (size_t)(w1_end - w1_start);
    memcpy(w_buf + w_len, ratio_str + w1_start, w1_len);
    w_len += w1_len;

    //group 2 (may be absent -> rm_so == -1).
    if (m[2].rm_so != -1) {
        int w2_start = m[2].rm_so;
        int w2_end   = m[2].rm_eo;
        size_t w2_len = (size_t)(w2_end - w2_start);
        memcpy(w_buf + w_len, ratio_str + w2_start, w2_len);
        w_len += w2_len;
    }

    w_buf[w_len] = '\0';

    //4. Extract H (group 3) into hbuf.
    char hbuf[64];
    int h_start = m[3].rm_so;
    int h_end = m[3].rm_eo;
    size_t h_len = (size_t)(h_end - h_start);
    memcpy(hbuf, ratio_str + h_start, h_len);
    hbuf[h_len] = '\0';

    //Done with regex.
    regfree(&re);

    //5. Convert and enforce W >= H.
    double w = strtod(w_buf, NULL);
    long h = strtol(hbuf, NULL, 10);

    if (w < (double)h) {
        return false;
    }

    return true;
}