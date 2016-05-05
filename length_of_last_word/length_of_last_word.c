/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Note:
Interestingly, the function definitions for the other languages implicitly provide the length of the string through .size() etc.
This means that the C implementation is forced to start at the beginning of the string instead of at the end.
*/

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char* skip_whitespace(const char* s) {
    while (isspace(*s)) {
        ++s;
    }

    return s;
}

int lengthOfLastWord(const char* s) {
    if (!s) {
        return 0;
    }

    s = skip_whitespace(s);
    if (*s == '\0') {
        return 0;
    }

    const char* beg = s;

    while (*s != '\0') {
        if (*s == ' ') {
            const char* temp = skip_whitespace(s);
            if (*temp == '\0') {
                return s - beg;
            }
            
            beg = s = temp;
        }

        ++s;
    }

    return (s == beg ? 0 : s - beg);
}

int main() {
    const char* const a = "uroi rsoihrg rsoibsgr oubsrg ohsrg";
    const char* const b = "It is fun and educational to program";
    const char* const c = "lsbrg oisrg oihae bpob     ";
    const char* const d = "";
    const char* const e = "              ";
    const char* const f = "x";
    const char* const g = "jlbrsgjbrpgsbrg";
    const char* const h = "    hello world";

    int alen = lengthOfLastWord(a);
    int blen = lengthOfLastWord(b);
    int clen = lengthOfLastWord(c);
    int dlen = lengthOfLastWord(d);
    int elen = lengthOfLastWord(e);
    int flen = lengthOfLastWord(f);
    int glen = lengthOfLastWord(g);
    int hlen = lengthOfLastWord(h);

    printf("a: %d\nb: %d\nc: %d\nd: %d\ne: %d\nf: %d\ng: %d\nh: %d\n",
           alen,
           blen,
           clen,
           dlen,
           elen,
           flen,
           glen,
           hlen);

    assert(alen == 5);
    assert(blen == 7);
    assert(clen == 4);
    assert(dlen == 0);
    assert(elen == 0);
    assert(flen == 1);
    assert(glen == 15);
    assert(hlen == 5);

    return 0;
}
