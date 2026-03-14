#include "../formats/aspect_ratio.h"

#ifndef SIMPLIFY_FRACTION_H
#define SIMPLIFY_FRACTION_H

long gcd(long w, long h);

void simplify_fraction(struct aspect_ratio_integer *ratio);

#endif