

#ifndef DEVIATION_H
#define DEVIATION_H

/**
 * delta_aspect_ratio() - Compute the deviation in ±% of the actual aspect ratio from the nominal aspect ratio.
 * @ar_actual: Pointer to variable representing the actual aspect ratio of a pixel raster.
 * @ar_nominal: Pointer to variable representing the nominal (targeted) aspect ratio.
 * 
 * Compute the deviation in ±% of @ar_actual from @ar_nominal.
 * 
 * Context: Any context.
 * Return: The signed deviation in percent of @ar_actual from @ar_nominal. 
 */
double delta_aspect_ratio(const double *ar_actual, const double *ar_nominal);

#endif