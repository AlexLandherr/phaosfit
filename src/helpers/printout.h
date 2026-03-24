#include "../formats/raster_pair.h"
#include "../formats/aspect_ratio.h"
#include "../arguments/arguments.h"

#ifndef PRINTOUT_H
#define PRINTOUT_H

/**
 * raster_pair_printout() - Prints all raster pairs to stdout as a formatted string with printf().
 * @pairs: Pointer to raster_pair_array object that holds all computed rasters to print out.
 * @ar_int: Pointer to aspect_ratio_integer object.
 * 
 * Prints all entries in @pairs to stdout as a formatted string using printf().
 * 
 * Context: Any context.
 * Return: None.
 */
void raster_pair_printout(const struct raster_pair_array *pairs, const struct aspect_ratio_integer *ar_int, const struct arguments *arg_ratio);

#endif