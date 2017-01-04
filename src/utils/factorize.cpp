#include "factorize.h"
#include <cmath>


ui factor(ui n) {
    // get the largest factor of n which is
    // <= sqrt(n)

    for (ui i = sqrt(n); i >= 2; --i)
        if (n % i == 0)
            return i;

    return 1;
}
