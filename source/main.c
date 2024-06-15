#include <stdio.h>
#include "for_uint64.h"

int main()
{
    // Initialise fibonacci_for_uint64 calculator
    fibonacci_for_uint64_init();

    // Calculate fibonacci_for_uint64 numbers
    for (int i = 0; i <= 92; i++)
    {
        printf("%2i -> ", i);
        uint64_t f = fibonacci_for_uint64(i);
        printf("%li\n", f);
    }

    // End program
    return 0;
}