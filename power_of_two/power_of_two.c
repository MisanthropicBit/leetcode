/* Given an integer, write a function to determine if it is a power of two. */

#include <assert.h>
#include <stdio.h>

int isPowerOfTwo(int n) {
    return (n > 0 && !(n & (n - 1)));
}

int main() {
    assert(isPowerOfTwo(32));
    assert(!isPowerOfTwo(75));
    assert(isPowerOfTwo(2));
    assert(!isPowerOfTwo(924));
    assert(!isPowerOfTwo(0));
    assert(!isPowerOfTwo(-2147483648));

    return 0;
}
