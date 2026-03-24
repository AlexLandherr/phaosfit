

#ifndef ASPECT_RATIO_H
#define ASPECT_RATIO_H

/**
 * struct aspect_ratio_decimal - Aspect ratio represented with decimal W and integer H.
 * @w: Width component of the aspect ratio, represented as a decimal value.
 * @h: Height component of the aspect ratio, represented as an integer value.
 *
 * Store an aspect ratio in W:H form where @w is a decimal value and @h is
 * an integer value.
 */
struct aspect_ratio_decimal {
    double w;
    long h;
};

/**
 * struct aspect_ratio_integer - Aspect ratio represented with integer W and H.
 * @w: Width component of the aspect ratio, represented as an integer value.
 * @h: Height component of the aspect ratio, represented as an integer value.
 *
 * Store an aspect ratio in W:H form where both @w and @h are integer values.
 */
struct aspect_ratio_integer {
    long w;
    long h;
};

#endif