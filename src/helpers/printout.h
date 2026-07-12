#include "../formats/raster_pair.h"
#include "../formats/aspect_ratio.h"
#include "../arguments/arguments.h"
#include <stdbool.h>
#include <stddef.h>

#ifndef PRINTOUT_H
#define PRINTOUT_H

#define DASH_LINE "------------------------------------------------------------------------------------------"

/**
 * raster_pair_printout_integer() - Prints all raster pairs to stdout as a formatted string with printf().
 * @pairs: Pointer to raster_pair_array object that holds all computed rasters to print out.
 * @ar_int: Pointer to aspect_ratio_integer object.
 * @arg_ratio: Pointer to arguments object containing the user-supplied ratio string.
 *
 * Prints all entries in @pairs to stdout as a formatted string using printf().
 *
 * Context: Any context.
 * Return: None.
 */
void raster_pair_printout_integer(const struct raster_pair_array *pairs, const struct aspect_ratio_integer *ar_int, const struct arguments *arg_ratio);

/**
 * raster_pair_printout_decimal() - Prints all raster pairs to stdout as a formatted string with printf().
 * @pairs: Pointer to raster_pair_array object that holds all computed rasters to print out.
 * @ar_dec: Pointer to aspect_ratio_decimal object.
 * @arg_ratio: Pointer to arguments object containing the user-supplied ratio string.
 *
 * Prints all entries in @pairs to stdout as a formatted string using printf().
 *
 * Context: Any context.
 * Return: None.
 */
void raster_pair_printout_decimal(const struct raster_pair_array *pairs, const struct aspect_ratio_decimal *ar_dec, const struct arguments *arg_ratio);

#endif