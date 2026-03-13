#include "../formats/aspect_ratio.h"
#include "../formats/raster_pair.h"

#ifndef FITTER_H
#define FITTER_H

struct raster_pair fitter_integer_ratio(const struct aspect_ratio_integer *ratio);

#endif