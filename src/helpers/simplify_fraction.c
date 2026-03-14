#include "simplify_fraction.h"
#include "../formats/aspect_ratio.h"

/*
Find the Greatest Common Divisor (GCD) of W and H using the Euclidean algorithm.
*/
long gcd(long w, long h) {
    if (h == 0) {
        return w;
    }

    return gcd(h, w % h);
}

/*
Simplify a aspect_ratio_integer struct's w and h members, modifies original object.
*/
void simplify_fraction(struct aspect_ratio_integer *ratio) {
    long gcd_result = gcd(ratio->w, ratio->h);
    ratio->w = ratio->w / gcd_result;
    ratio->h = ratio->h / gcd_result;
}