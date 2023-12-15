//
// Created by Messi on 2023/12/6.
//

#include "sort.h"

// 冒泡
void sort::bubbleSort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if (nums[i] > nums[j]) {
                int temp = nums[i];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }
}

// 选择
void sort::simpleSelectSort(std::vector<int> &nums) {
    int min, temp;
    for (int i = 0; i < nums.size() - 1; ++i) {
        min = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;
        }
    }
}

// 插入
void sort::insertSort(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int key = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

// 希尔
void sort::shellSort(std::vector<int> &nums) {

}

// 快排
void sort::quickSort(std::vector<int> &nums, int L, int R) {
    if (L >= R) {
        return; // 递归结束条件
    }
    int left = L, right = R;
    int key = nums[left];
    while (left < right) {
        // 处理右边界，直到遇到小于key的
        while (left < right && nums[right] >= key) {
            right--;
        }
        if (left < right) {
            nums[left] = nums[right];
            // 此时right位为空
        }
        // 处理左边界
        while (left < right && nums[left] <= key) {
            left++;
        }
        if (left < right) {
            nums[right] = nums[left];
            // 此时right为不为空，left位为空
        }
        if (left >= right) {
            // 现在已经找打了key的最终位置
            nums[left] = key;
        }
    }
    // 分别递归左右子序列
    quickSort(nums, L, left - 1);
    quickSort(nums, left + 1, R);
}
