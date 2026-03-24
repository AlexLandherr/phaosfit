

#ifndef RASTER_PAIR_H
#define RASTER_PAIR_H

struct raster_pair {
    long raster_w;
    long raster_h;
};

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