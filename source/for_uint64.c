#include <stdlib.h>
#include "for_uint64.h"

// Last index in `_fib_buffer`.
int _fib_last_number = 0;

// Save calculated fibonacci numbers.
uint64_t *_fib_buffer = NULL;

void fibonacci_for_uint64_init()
{
    // Free already allocated memory
    if (_fib_buffer != NULL)
    {
        _fib_last_number = 0;
        free(_fib_buffer);
    }

    // Allocate memory for variables
    _fib_buffer = (uint64_t *)malloc(sizeof(uint64_t) * 3);
    if (_fib_buffer == NULL) exit(1);

    // Set variables to default values
    _fib_last_number = 2;
    _fib_buffer[0] = 0;
    _fib_buffer[1] = 1;
    _fib_buffer[2] = 1;
}

uint64_t fibonacci_for_uint64(int n)
{
    // The result will be out of bound
    if (n < 0 || n > 92) return 0;
    // The internal variables aren't initialized
    if (_fib_buffer == NULL || _fib_last_number == 0) return 0;
    // fib(n) has already been calculated
    if (n <= _fib_last_number) return _fib_buffer[n];

    // Expanding fibonacci_for_uint64 buffer
    _fib_buffer = realloc(_fib_buffer, sizeof(uint64_t) * (n + 1));
    if (_fib_buffer == NULL) exit(1);

    // Calculate fibonacci_for_uint64 number
    do
    {
        _fib_last_number += 1;
        _fib_buffer[_fib_last_number] = _fib_buffer[_fib_last_number-1] + _fib_buffer[_fib_last_number-2];
    }
    while (_fib_last_number < n);

    // Return result
    return _fib_buffer[_fib_last_number];
}