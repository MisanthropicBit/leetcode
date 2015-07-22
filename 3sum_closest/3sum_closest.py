#!/usr/bin/env python
# -*- coding: utf8 -*-

# Given an array S of n integers, find three integers in S such that the sum
# is closest to a given number, target. Return the sum of the three integers.
# You may assume that each input would have exactly one solution.
#
# For example, given array S = {-1 2 1 -4}, and target = 1.
# The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

import sys
import random
import itertools as it


class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        num.sort()  # Ω(N log(N))
        diff, r = sys.maxint, 0

        for i in range(len(num)-2):
            j, k = i+1, len(num)-1

            while j < k:
                s = num[i] + num[j] + num[k]
                ds = target - s
                #print "{} + {} + {} = {}".format(num[i], num[j], num[k], s)

                if abs(ds) < diff:
                    r = s
                    diff = abs(ds)

                #print s, ds
                if s < target:
                    j += 1
                    #print "j:", j
                elif s > target:
                    k -= 1
                    #print "k:", k
                else:
                    # We found the answer (although there may be more)
                    return target

        return r


if __name__ == '__main__':
    s = Solution()

    # Sanity check 1
    r = s.threeSumClosest([-1, 2, 1, -4], 1)
    print "Closest sum to {} is {}".format(1, r)
    assert r == 2

    # Sanity check 2
    r = s.threeSumClosest([1, 2, 4, 8, 16, 32, 64, 128],  82)
    print "Closest sum to {} is {}".format(82, r)
    assert r == 82
    
    # Check result with a random list of numbers
    l = [random.randrange(-1000, 1000) for i in range(100)]
    i, j, k, v = 0, 0, 0, random.randrange(-2997, 2998)
    mn = sys.maxint

    for a, b, c in it.combinations(l, 3):
        temp = abs((a + b + c) - v)

        if temp < mn:
            i, j, k = a, b, c
            mn = temp

    print "Brute-force sum is {}, method returns {}, and value is {}"\
        .format(i+j+k, s.threeSumClosest(l, v), v)
