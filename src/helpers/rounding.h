#include <stdint.h>

#ifndef ROUNDING_H
#define ROUNDING_H

/**
 * enum nearest_even_status - Result of rounding a double to an even integer.
 * @NEAREST_EVEN_OK: The value was successfully converted.
 * @NEAREST_EVEN_ODD_INTEGER: The value was an exact odd integer and was ignored.
 * @NEAREST_EVEN_OUT_OF_RANGE: The resulting value was outside the permitted range.
 * @NEAREST_EVEN_INVALID: An argument was invalid or the value was not finite.
 */
enum nearest_even_status {
    NEAREST_EVEN_OK,
    NEAREST_EVEN_ODD_INTEGER,
    NEAREST_EVEN_OUT_OF_RANGE,
    NEAREST_EVEN_INVALID
};

/**
 * nearest_even_uint64() - Round a double to the nearest even integer.
 * @value: Floating-point value to process.
 * @min_value: Smallest permitted result.
 * @max_value: Largest permitted result.
 * @result: Pointer receiving the resulting even integer.
 *
 * Exact odd integer values, such as 3.0 and 5.0, are not rounded and instead
 * produce NEAREST_EVEN_ODD_INTEGER. Non-integer values are rounded to the
 * nearest even integer.
 *
 * Context: Any context.
 * Return: A nearest_even_status value describing the result.
 */
enum nearest_even_status nearest_even_uint64(double value, uint64_t min_value, uint64_t max_value, uint64_t *result);

#endif