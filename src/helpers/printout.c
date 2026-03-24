#include "printout.h"
#include "../formats/raster_pair.h"
#include "../formats/aspect_ratio.h"
#include "../helpers/deviation.h"
#include "../arguments/arguments.h"
#include <stdio.h>

//delta character -> Δ
void raster_pair_printout(const struct raster_pair_array *pairs, const struct aspect_ratio_integer *ar_int, const struct arguments *arg_ratio) {
    printf("\n");
    for (unsigned long i = 0; i < pairs->count; i++) {
        double actual_aspect_ratio = (double)pairs->array[i].raster_w / (double)pairs->array[i].raster_h;
        double nominal_aspect_ratio = (double)ar_int->w / (double)ar_int->h;
        
        //printf("W_pix: %ld, H_pix: %ld ", pairs->array[i].raster_w, pairs->array[i].raster_h);
        //printf("Deviation from %s (±%%): %.15lf\n", arg_ratio->ratio, delta_aspect_ratio(&actual_aspect_ratio, &nominal_aspect_ratio));
    }
}