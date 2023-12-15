//
// Created by Messi on 2023/12/6.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 面试经典150题
class Solution {
    /// 数组 / 字符串
public:
    // 88.合并两个有序数组
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);
    // 27.移除元素
    int removeElement(vector<int> &nums, int val);
    // 26.删除有序数组中的重复项
    int removeDuplicates(vector<int> &nums);
    // 80.删除有序数组中的重复项 II
    int removeDuplicates_2(vector<int> &nums);
    // 169.多数元素
    int majorityElement(vector<int> &nums);
    // 189. 轮转数组
    void rotate(vector<int> &nums, int k);
    // 121. 买卖股票的最佳时机
    int maxProfit(vector<int> &prices);
    // 122. 买卖股票的最佳时机 II
    int maxProfit_2(vector<int> &prices);
    // 55. 跳跃游戏
    bool canJump(vector<int>& nums);

    /// 双指针
public:
    // 125. 验证回文串
    bool isPalindrome(string s);
    // 392. 判断子序列
    bool isSubsequence(string s, string t);
    // 167. 两数之和 II - 输入有序数组
    vector<int> twoSum(vector<int>& numbers, int target);
    // 11. 盛最多水的容器
    int maxArea(vector<int>& height);

    /// 滑动窗口
    /*
     * 滑动窗口可以配合队列或者hash解决类似子串子数组的问题
     * */
public:
    // 209. 长度最小的子数组
    int minSubArrayLen(int target, vector<int>& nums);
    // 3. 无重复字符的最长子串
    int lengthOfLongestSubstring(string s);

    /// 哈希表
public:

    /// 链表
public:

    /// 二叉树
public:
    // 104. 二叉树的最大深度
    int maxDepth(TreeNode* root);
    // 100. 相同的树
    bool isSameTree(TreeNode* p, TreeNode* q);

    /// 回溯/分治
public:

};

#endif //ALGORITHM_SOLUTION_H
