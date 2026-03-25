#include "printout.h"
#include "../formats/raster_pair.h"
#include "../formats/aspect_ratio.h"
#include "../helpers/deviation.h"
#include "../arguments/arguments.h"
#include <stdio.h>

#define WIDTH_COL_W        16
#define HEIGHT_COL_W       16
#define DELTA_COL_W        22
#define PLACEHOLDER_COL_W  24

void raster_pair_printout(const struct raster_pair_array *pairs, const struct aspect_ratio_integer *ar_int, const struct arguments *arg_ratio) {
    char delta_title[sizeof(arg_ratio->ratio) + sizeof("Δ% from ") - 1]; //Dynamically set delta_title to the right size in bytes.
    snprintf(delta_title, sizeof(delta_title), "Δ%% from %s", arg_ratio->ratio);

    printf("%s\n", DASH_LINE);
    printf("| %*s | %*s | %*s | %-*s |\n", WIDTH_COL_W, "Width (px)", HEIGHT_COL_W, "Height (px)", DELTA_COL_W, delta_title, PLACEHOLDER_COL_W, "PLACEHOLDER_FIELD");
    printf("%s\n", DASH_LINE);
    
    for (unsigned long i = 0; i < pairs->count; i++) {
        double actual_aspect_ratio = (double)pairs->array[i].raster_w / (double)pairs->array[i].raster_h;
        double nominal_aspect_ratio = (double)ar_int->w / (double)ar_int->h;
        double delta_ar = delta_aspect_ratio(&actual_aspect_ratio, &nominal_aspect_ratio);
        
        printf("| %*ld | %*ld | %+20.15f%% | %-*s |\n", WIDTH_COL_W, pairs->array[i].raster_w, HEIGHT_COL_W, pairs->array[i].raster_h, delta_ar, PLACEHOLDER_COL_W, "EMPTY_PLACEHOLDER_STR");
        printf("%s\n", DASH_LINE);
    }
}