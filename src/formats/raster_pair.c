#include "raster_pair.h"
#include <stdlib.h>
#include <stdio.h>

/*
Add/append a raster_pair struct object to the end of a
raster_pair_array struct array. If array is empty added
object will be added at the first/0-th index.
*/
void append_raster_pair_array(struct raster_pair_array *dst_array, struct raster_pair pair) {
    if (dst_array->count == 0) {
        dst_array->array = malloc(sizeof(struct raster_pair));
        if (!dst_array->array) {
            printf("malloc() failed, not enough memory!\n");
            exit(EXIT_FAILURE);
        }
    } else {
        int new_size = (dst_array->count + 1) * sizeof(struct raster_pair);
        struct raster_pair *tmp = realloc(dst_array->array, new_size);
        if (!tmp) {
            printf("realloc() failed, not enough memory!\n");
        } else {
            dst_array->array = tmp;
        }
    }

    dst_array->array[dst_array->count] = pair;
    dst_array->count++;
}