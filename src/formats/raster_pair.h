

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

void append_raster_pair_array(struct raster_pair_array *dst_array, struct raster_pair pair);

#endif