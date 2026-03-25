

#ifndef RASTER_PAIR_H
#define RASTER_PAIR_H

/**
 * struct raster_pair - The computed pixel raster dimensions fitting a given aspect ratio.
 * @raster_w: width component of the pixel raster.
 * @raster_h: height component of the pixel raster.
 * 
 * Store the computed pixel raster dimensions that fit a given aspect ratio.
 */
struct raster_pair {
    long raster_w;
    long raster_h;
};

/**
 * struct raster_pair_array - Array of computed pixel raster dimensions.
 * @array: Pointer to the array of raster_pair objects.
 * @count: Number of raster_pair objects stored in @array.
 *
 * Store an array of computed pixel raster dimensions that fit a given aspect
 * ratio, together with the number of elements in the array.
 */
struct raster_pair_array {
    struct raster_pair *array;
    unsigned long count;
};

/**
 * append_raster_pair_array() - Add/append a raster pair to the end of a raster_pair_array.
 * @dst_array: Pointer to the raster_pair_array object to add/append to.
 * @pair: raster_pair to add/append to @dst_array.
 * 
 * If @dst_array is empty added object will end up at the first (0-th index).
 * 
 * Context: Any context.
 * Return: None.
*/
void append_raster_pair_array(struct raster_pair_array *dst_array, struct raster_pair pair);

#endif