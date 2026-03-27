#include "fitter.h"
#include "../formats/aspect_ratio.h"
#include "../formats/raster_pair.h"
#include "../constants/video_resolutions.h"
#include "../helpers/simplify_fraction.h"
#include <stdbool.h>

void fitter_integer_ratio(struct aspect_ratio_integer *ratio, struct raster_pair_array *dst_array) {
    //Can aspect ratio be simplified?
    long ar_gcd = gcd(ratio->w, ratio->h);
    if (ar_gcd != 1) {
        //Can be simplified.
        simplify_fraction(ratio);
    } //Else (ar_gcd == 1) -> cannot be simplified further.

    //Is aspect ratio even (i.e. are W and H even)?
    if (ratio->w % 2 != 0 && ratio->h % 2 != 0) {
        //Not even, multiply W and H by 2.
        ratio->w = ratio->w * 2;
        ratio->h = ratio->h * 2;
    } //Else, they are even no need to multiply W and H by 2.

    /*
    Multiply W and H by all even integers from 2 and up as long as the product of
    W * i and H * i are less than W_MAX_RESOLUTION_PIXELS (or H_MAX_RESOLUTION_PIXELS since they're equal).

    Like so:
    W * 2, H * 2
    W * 4, H * 4
    W * 6, H * 6
    ...
    as long as none of the products are greater than W_MAX_RESOLUTION_PIXELS.
    */
    long i = 2;
    while (true) {
        long raster_pair_w = ratio->w * i;
        long raster_pair_h = ratio->h * i;

        if (raster_pair_w > W_MAX_RESOLUTION_PIXELS || raster_pair_h > W_MAX_RESOLUTION_PIXELS) {
            break;
        } else {
            struct raster_pair array_pair_entry = {raster_pair_w, raster_pair_h};
            append_raster_pair_array(dst_array, array_pair_entry);
            i += 2;
        }
    }
}
