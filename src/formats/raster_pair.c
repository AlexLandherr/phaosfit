#include "raster_pair.h"
#include <stdlib.h>
#include <stdio.h>

/*
Add/append a raster_pair struct object to the end of a
raster_pair_array struct array. If array is empty added
object will be added at the first/0-th index.

if (list->count == 0) {
    list->all_cards_list = malloc(sizeof(struct card));
    if (!list->all_cards_list) {
        printf("malloc() failed, not enough memory!\n");
        exit(EXIT_FAILURE);
    }
} else {
    int new_size = (list->count + 1) * sizeof(struct card);
    struct card *tmp = realloc(list->all_cards_list, new_size);
    if (!tmp) {
        printf("realloc() failed, not enough memory!\n");
    } else {
        list->all_cards_list = tmp;
    }
}

//Setting card_id to card_num.
list->all_cards_list[list->count].card_id = card_num;

//Setting new card to have access by default.
list->all_cards_list[list->count].has_access = true;

//Getting UTC date and time, convert it to 'YYYY-MM-DD HH:MM:SS UTC' string and setting creation_time to said string.
strcpy(list->all_cards_list[list->count].creation_time, UTC_date_time_str("%F %T UTC"));

char buf[128];
card_as_str_printout(&list->all_cards_list[list->count], buf, sizeof(buf));
printf("New card '%d' added:\n%s\n", card_num, buf);
list->count++;
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