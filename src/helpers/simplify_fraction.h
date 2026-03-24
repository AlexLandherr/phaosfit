#include "../formats/aspect_ratio.h"

#ifndef SIMPLIFY_FRACTION_H
#define SIMPLIFY_FRACTION_H

long gcd(long w, long h);

/**
 * simplify_fraction() - Simplify an aspect ratio in place.
 * @ratio: Pointer to the aspect ratio object to simplify.
 *
 * Simplify the @w and @h members of *@ratio by dividing both values by
 * their greatest common divisor. The original object is modified.
 *
 * Context: Any context.
 * Return: None.
 */
void simplify_fraction(struct aspect_ratio_integer *ratio);

#endif