#include "../formats/aspect_ratio.h"
#include "../formats/raster_pair.h"

#ifndef FITTER_H
#define FITTER_H

/**
 * fitter_integer_ratio() - Compute all pixel rasters that match a given aspect ratio.
 * @ratio: Pointer to the aspect ratio object.
 * @dst_array: Pointer to the raster_pair_array object that will hold all computed rasters.
 * 
 * Computes all pixel rasters that match a given aspect ratio when W and H both are integers.
 * See function definition for algorithm details in 'fitter.c'
 * 
 * Context: Any context.
 * Return: None.
 */
void fitter_integer_ratio(struct aspect_ratio_integer *ratio, struct raster_pair_array *dst_array);

#endif