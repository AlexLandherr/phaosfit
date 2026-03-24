#include "../formats/aspect_ratio.h"
#include <stdbool.h>

#ifndef PARSE_H
#define PARSE_H

/**
 * W_is_float_str() - Check if the W part of a valid aspect ratio string is a floating-point value.
 * @ratio_str: Pointer to first char of the string representing the aspect ratio.
 * 
 * Checking if the W (width) part of the aspect ratio string is a floating-point value is needed
 * in order to determine which parser function to use.
 * 
 * Context: Any context.
 * Return: A boolean indicating if the W is a floating-point value or not.
 */
bool W_is_float_str(char *ratio_str);

/**
 * parse_aspect_ratio_decimal() - Parse aspect ratio when W is a decimal/floating-point value.
 * @ratio_str: Pointer to first char of the string representing the aspect ratio.
 * 
 * Parse the aspect ratio when W_is_float_str() has determined that W is a floating-point value,
 * e.g. "1.85:1" or "2.39:1" etc.
 * 
 * Context: Any context.
 * Return: aspect_ratio_decimal struct representing the parsed W floating-point value and the integer H value.
 */
struct aspect_ratio_decimal parse_aspect_ratio_decimal(char *ratio_str);

/**
 * parse_aspect_ratio_integer() - Parse aspect ratio when W is a integer value.
 * @ratio_str: Pointer to first char of the string representing the aspect ratio.
 * 
 * Parse the aspect ratio when W_is_float_str() has determined that W is a integer value,
 * e.g. "16:9" or "4:3" etc.
 * 
 * Context: Any context.
 * Return: aspect_ratio_integer struct representing the parsed W integer value and the integer H value.
 */
struct aspect_ratio_integer parse_aspect_ratio_integer(char *ratio_str);

#endif