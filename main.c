#include <stdio.h>
#include <limits.h>
#include "math2.h"

int main(void) {
    unsigned int x = generate_prime(13, 47); // We don't want to go any higher to avoid overflowing uint32
    unsigned int fib = fibonacci(x);

    printf("The %dth Fibonacci number is %d\n", x, fib);

    return 0;
}
