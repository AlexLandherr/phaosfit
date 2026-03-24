#include <stdbool.h>

#ifndef VALIDATION_H
#define VALIDATION_H

#define RATIO_PATTERN "^([1-9][0-9]*)(\\.[0-9]{0,15})?:([1-9][0-9]*)$"

/**
 * is_valid_ratio_str() - Validate an aspect ratio string in W:H form.
 * @ratio_str: Pointer to the ratio string to validate.
 *
 * Validate that @ratio_str matches the accepted W:H aspect-ratio syntax and
 * that W is greater than or equal to H.
 *
 * Context: Any context.
 * Return: true if @ratio_str is valid, otherwise false.
 */
bool is_valid_ratio_str(char *ratio_str);

#endif