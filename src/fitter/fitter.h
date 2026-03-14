#include "../formats/aspect_ratio.h"
#include "../formats/raster_pair.h"

#ifndef FITTER_H
#define FITTER_H

void fitter_integer_ratio(struct aspect_ratio_integer *ratio, struct raster_pair_array *dst_array);

#endif