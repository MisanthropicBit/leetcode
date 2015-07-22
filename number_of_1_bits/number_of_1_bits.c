/*Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.*/

#include <stdint.h>
#include <stdio.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    
    for (unsigned int i = 0; i < sizeof(n) * 8; ++i) {
        if (n >> i & 0x1) {
            ++count;
        }
    }
    
    return count;
}

int main() {
    printf("Hamming weight of 11 is %d\n", hammingWeight(11));

    return 0;
}
