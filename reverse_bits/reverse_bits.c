/*Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?*/

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    // Swap every second bit
    n = ((n >> 1) & 0x55555555u) | ((n & 0x55555555u) << 1);
    // Swap every pair of 2 bits (16 pairs in total)
    n = ((n >> 2) & 0x33333333u) | ((n & 0x33333333u) << 2);
    // Swap every pair of 4 bits (8 pairs in total)
    n = ((n >> 4) & 0x0f0f0f0fu) | ((n & 0x0f0f0f0fu) << 4);
    // Swap every pair of 8 bits (4 pairs in total)
    n = ((n >> 8) & 0x00ff00ffu) | ((n & 0x00ff00ffu) << 8);
    // Swap every pair of 16 bits (2 pairs in total)
    n = ((n >> 16) & 0xffffu) | ((n & 0xffffu) << 16);

    return n;
}

int main() {
    printf("%d reversed is %d\n", 43261596, reverseBits(43261596));
    printf("%d reversed is %d\n", 12, reverseBits(0b00000000000000000000000000001100));

    return 0;
}
