#include <stdlib.h>
#include "math2.h"

unsigned int fibonacci(unsigned int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned int is_prime(unsigned int n) {
    if (n <= 1) {
        return 0;
    }

    for (unsigned int x = 2; x <= n / 2; x++) {
        if (n % x == 0) {
            return 0;
        }
    }

    return 1;
}

unsigned int generate_prime(unsigned int min, unsigned int max) {
    unsigned int number;

    while (1) {
        number = arc4random() % (max - min + 1) + min;

        if (is_prime(number)) {
            return number;
        }
    }
}
