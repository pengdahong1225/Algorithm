#include <iostream>
#include "mianshiJD150/Solution.h"

int main() {
    Solution func;

    std::vector<int> nums{2,3,1,2,4,3};
    std::vector<int> nums1{1,4,4};
    std::vector<int> nums2{1,1,1,1,1,1,1,1};
    std::string s("abcabcbb");
    std::cout << func.lengthOfLongestSubstring(s) << std::endl;
    return 0;
}
