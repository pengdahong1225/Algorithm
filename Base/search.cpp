//
// Created by Messi on 2023/12/6.
//

#include "search.h"

int search::binarySearch(std::vector<int> &nums, int elem) {
    int left = 0, right = nums.size() - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (elem < nums[mid]) {
            right = mid - 1;
        } else if (elem > nums[mid + 1]) {
            left = mid + 1;
        } else {
            return mid;
        }
        return -1;
    }
}
