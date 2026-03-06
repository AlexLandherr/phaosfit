#include "deviation.h"

/*
Calculate the deviation of the actual aspect ratio from
the nominal aspect ratio in ±%.
*/
double delta_aspect_ratio(double *ar_actual, double *ar_nominal) {
    return ((*ar_actual / *ar_nominal) - 1.0) * 100.0;
}