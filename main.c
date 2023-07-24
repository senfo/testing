#include <stdio.h>
#include <limits.h>
#include "math2.h"

int main(void) {
    unsigned int x = generate_prime(13, 100);
    unsigned int fib = fibonacci(x);

    printf("The %dth Fibonacci number is %d\n", x, fib);

    return 0;
}
