/* Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Alternative solution:
Sort the vector, then scan through it and look for adjacent, equal elements
*/

#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(const std::vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }

        std::set<int> set(nums.cbegin(), nums.cend());

        return nums.size() != set.size();
    }
};

int main() {
    Solution s;

    std::vector<int> a{1, 2, 3, 4, 6, 3};
    std::vector<int> b{2, 8, 5, 6, 0, 1};
    std::vector<int> c;

    std::cout << std::boolalpha;
    std::cout << s.containsDuplicate(a) << ", "
              << s.containsDuplicate(b) << ", "
              << s.containsDuplicate(c) << std::endl;
}
