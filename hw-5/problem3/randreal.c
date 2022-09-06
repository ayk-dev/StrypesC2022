#include <stdio.h>
#include <stdlib.h>

#include "randreal.h"

double randreal(double min, double max);

double randreal(double min, double max) {
    return min + ((double) rand() / RAND_MAX) * (max - min);
}
