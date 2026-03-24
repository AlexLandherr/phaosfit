#include "deviation.h"

double delta_aspect_ratio(const double *ar_actual, const double *ar_nominal) {
    return ((*ar_actual / *ar_nominal) - 1.0) * 100.0;
}