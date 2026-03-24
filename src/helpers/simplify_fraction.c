#include "simplify_fraction.h"
#include "../formats/aspect_ratio.h"

/**
 * gcd() - Compute the greatest common divisor of two integers.
 * @w: Width given as a dimensionless integer value.
 * @h: Height given as a dimensionless integer value.
 *
 * Compute the greatest common divisor (GCD) of @w and @h using the
 * Euclidean algorithm.
 *
 * Context: Any context.
 * Return: The greatest common divisor of @w and @h.
 */
long gcd(long w, long h) {
    if (h == 0) {
        return w;
    }

    return gcd(h, w % h);
}

void simplify_fraction(struct aspect_ratio_integer *ratio) {
    long gcd_result = gcd(ratio->w, ratio->h);
    ratio->w = ratio->w / gcd_result;
    ratio->h = ratio->h / gcd_result;
}