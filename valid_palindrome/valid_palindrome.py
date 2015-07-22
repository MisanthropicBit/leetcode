#!/usr/bin/env python
# -*- coding: utf8 -*-

# Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
#
# For example,
# "A man, a plan, a canal: Panama" is a palindrome.
# "race a car" is not a palindrome.
#
# Note:
# Have you consider that the string might be empty? This is a good question to ask during an interview.
#
# For the purpose of this problem, we define empty string as valid palindrome.

class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        if not s:
            return True

        i, j = 0, len(s)-1

        while i < j:
            # Move i and j until they both index alphanumeric characters
            while not s[i].isalnum() and i < j:
                i += 1

            while not s[j].isalnum() and j > i:
                j -= 1

            if s[i].lower() != s[j].lower():
                return False
            else:
                j -= 1
                i += 1

        return True


if __name__ == '__main__':
    s = Solution()

    assert s.isPalindrome("A man, a plan, a canal: Panama")
    assert s.isPalindrome(".,")
