#include "rounding.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>

enum nearest_even_status nearest_even_uint64(double value, uint64_t min_value, uint64_t max_value, uint64_t *result) {
    double integer_part;

    if (result == NULL || !isfinite(value) || value < 0.0 || min_value > max_value) {
        return NEAREST_EVEN_INVALID;
    }

    /*
     * Detect values whose stored double representation is exactly an integer.
     */
    if (modf(value, &integer_part) == 0.0) {
        if (integer_part < (double)min_value || integer_part > (double)max_value) {
            return NEAREST_EVEN_OUT_OF_RANGE;
        }

        uint64_t integer_value = (uint64_t)integer_part;

        if ((integer_value & UINT64_C(1)) != 0) {
            return NEAREST_EVEN_ODD_INTEGER;
        }

        *result = integer_value;

        return NEAREST_EVEN_OK;
    }

    double lower_even = floor(value / 2.0) * 2.0;
    double upper_even = ceil(value / 2.0) * 2.0;

    double lower_distance = value - lower_even;
    double upper_distance = upper_even - value;

    /*
     * An exact tie normally means that value is an odd integer. That case was
     * handled above, but retain this check defensively.
     */
    if (lower_distance == upper_distance) {
        return NEAREST_EVEN_ODD_INTEGER;
    }

    double nearest_even;

    if (lower_distance < upper_distance) {
        nearest_even = lower_even;
    } else {
        nearest_even = upper_even;
    }

    if (nearest_even < (double)min_value || nearest_even > (double)max_value) {
        return NEAREST_EVEN_OUT_OF_RANGE;
    }

    *result = (uint64_t)nearest_even;

    return NEAREST_EVEN_OK;
}