#define _XOPEN_SOURCE 700

#include "printout.h"
#include "../formats/raster_pair.h"
#include "../formats/aspect_ratio.h"
#include "../helpers/deviation.h"
#include "../arguments/arguments.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <float.h>
#include <stdlib.h>
#include <wchar.h>

#define WIDTH_COL_W        16
#define HEIGHT_COL_W       16
#define DELTA_COL_W        22
#define PLACEHOLDER_COL_W  24

static int utf8_display_width(const char *s) {
    size_t wchar_count = mbstowcs(NULL, s, 0);

    if (wchar_count == (size_t)-1) {
        return -1;
    }

    wchar_t *wbuf = malloc((wchar_count + 1) * sizeof(*wbuf));
    if (wbuf == NULL) {
        return -1;
    }

    if (mbstowcs(wbuf, s, wchar_count + 1) == (size_t)-1) {
        free(wbuf);
        return -1;
    }

    int display_width = wcswidth(wbuf, wchar_count);

    free(wbuf);

    return display_width;
}

static void print_right_aligned_display_width(const char *s, int field_width) {
    int display_width = utf8_display_width(s);

    if (display_width < 0) {
        printf("%*s", field_width, s);
        return;
    }

    int padding = field_width - display_width;
    if (padding < 0) {
        padding = 0;
    }

    printf("%*s%s", padding, "", s);
}

void raster_pair_printout_integer(const struct raster_pair_array *pairs, const struct aspect_ratio_integer *ar_int, const struct arguments *arg_ratio) {
    char delta_title[sizeof(arg_ratio->ratio) + sizeof("Δ% from ") - 1]; //Dynamically set delta_title to the right size in bytes.
    snprintf(delta_title, sizeof(delta_title), "Δ%% from %s", arg_ratio->ratio);

    printf("%s\n", DASH_LINE);
    printf("| %*s | %*s | ", WIDTH_COL_W, "Width (px)", HEIGHT_COL_W, "Height (px)");
    print_right_aligned_display_width(delta_title, DELTA_COL_W);
    printf(" | %-*s |\n", PLACEHOLDER_COL_W, "PLACEHOLDER_FIELD");
    printf("%s\n", DASH_LINE);

    for (uint64_t i = 0; i < pairs->count; i++) {
        double actual_aspect_ratio = (double)pairs->array[i].raster_w / (double)pairs->array[i].raster_h;
        double nominal_aspect_ratio = (double)ar_int->w / (double)ar_int->h;
        double delta_ar = delta_aspect_ratio(&actual_aspect_ratio, &nominal_aspect_ratio);

        printf("| %*" PRIu64 " | %*" PRIu64 " | %+*.*g%% | %-*s |\n",
               WIDTH_COL_W, pairs->array[i].raster_w,
               HEIGHT_COL_W, pairs->array[i].raster_h,
               DELTA_COL_W - 1, DBL_DIG, delta_ar,
               PLACEHOLDER_COL_W, "EMPTY_PLACEHOLDER_STR"
        );
        printf("%s\n", DASH_LINE);
    }
}

void raster_pair_printout_decimal(const struct raster_pair_array *pairs, const struct aspect_ratio_decimal *ar_dec, const struct arguments *arg_ratio) {
    char delta_title[sizeof(arg_ratio->ratio) + sizeof("Δ% from ") - 1]; //Dynamically set delta_title to the right size in bytes.
    snprintf(delta_title, sizeof(delta_title), "Δ%% from %s", arg_ratio->ratio);

    printf("%s\n", DASH_LINE);
    printf("| %*s | %*s | ", WIDTH_COL_W, "Width (px)", HEIGHT_COL_W, "Height (px)");
    print_right_aligned_display_width(delta_title, DELTA_COL_W);
    printf(" | %-*s |\n", PLACEHOLDER_COL_W, "PLACEHOLDER_FIELD");
    printf("%s\n", DASH_LINE);

    for (uint64_t i = 0; i < pairs->count; i++) {
        double actual_aspect_ratio = (double)pairs->array[i].raster_w / (double)pairs->array[i].raster_h;
        double nominal_aspect_ratio = ar_dec->w / (double)ar_dec->h;
        double delta_ar = delta_aspect_ratio(&actual_aspect_ratio, &nominal_aspect_ratio);

        printf("| %*" PRIu64 " | %*" PRIu64 " | %+*.*g%% | %-*s |\n",
               WIDTH_COL_W, pairs->array[i].raster_w,
               HEIGHT_COL_W, pairs->array[i].raster_h,
               DELTA_COL_W - 1, DBL_DIG, delta_ar,
               PLACEHOLDER_COL_W, "EMPTY_PLACEHOLDER_STR"
        );
        printf("%s\n", DASH_LINE);
    }
}