#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <stdint.h>

/**
 * Load default internal variables required for calculating fibonacci_for_uint64 numbers. Calling this multiple
 * times will reset the variables and free their allocated memory.
 */
void fibonacci_for_uint64_init();

/** Returns the fibonacci_for_uint64 number for `n` as `uint64_t`. */
uint64_t fibonacci_for_uint64(int n);

#endif