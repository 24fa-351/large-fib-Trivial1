#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define the widest possible integer type (using typedef for flexibility)
typedef uint64_t fib_type;

// Recursive Fibonacci function
fib_type fib_recursive(fib_type n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci function
fib_type fib_iterative(fib_type n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    fib_type prev1 = 0, prev2 = 1, current = 0;
    for (fib_type i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return current;
}

// Function to detect overflow during addition
int check_overflow(fib_type a, fib_type b) {
    return (a > UINT64_MAX - b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./fib <integer> <method (r/i)>\n");
        return 1;
    }

    // Parse command-line arguments
    fib_type n = atoi(argv[1]);
    char method = argv[2][0];

    if (method != 'r' && method != 'i') {
        printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    // Compute Fibonacci number
    fib_type result;
    if (method == 'r') {
        result = fib_recursive(n);
    } else {
        result = fib_iterative(n);
    }

    // Output the result
    printf("%lu\n", result);
    return 0;
}
