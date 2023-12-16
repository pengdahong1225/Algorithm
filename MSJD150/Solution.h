//
// Created by Messi on 2023/12/6.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "source.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

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
    bool canJump(vector<int> &nums);

    /// 双指针
public:
    // 125. 验证回文串
    bool isPalindrome(string s);
    // 392. 判断子序列
    bool isSubsequence(string s, string t);
    // 167. 两数之和 II - 输入有序数组
    vector<int> twoSum(vector<int> &numbers, int target);
    // 11. 盛最多水的容器
    int maxArea(vector<int> &height);

    /// 滑动窗口
    // 滑动窗口可以配合队列或者hash解决类似子串子数组的问题
public:
    // 209. 长度最小的子数组
    int minSubArrayLen(int target, vector<int> &nums);
    // 3. 无重复字符的最长子串
    int lengthOfLongestSubstring(string s);

    /// 哈希表
public:
    bool isIsomorphic(string s, string t);

    /// 链表
public:

    /// 二叉树
public:
    // 104. 二叉树的最大深度
    int maxDepth(TreeNode *root);
    // 100. 相同的树
    bool isSameTree(TreeNode *p, TreeNode *q);
    // 226. 翻转二叉树
    TreeNode *invertTree(TreeNode *root);
    // 101. 对称二叉树
    bool isSymmetric(TreeNode* root);

    /// 回溯/分治
public:

    /// 其他
public:
    // 最近公共祖先
    /* 最近公共祖先的定义： 设节点 root 为节点 p,q 的某公共祖先，若其左子节点 root.left
    和右子节点 root.right 都不是 p,q 的公共祖先，则称 root 是 “最近的公共祖先”. */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
    TreeNode *lowestCommonAncestor_2(TreeNode *root, TreeNode *p, TreeNode *q);
    // 二叉搜索树的第K大节点
    int kthLargest(TreeNode *root, int k);
    // 单词搜索
    bool exist(vector<vector<char>> &board, string word);
    bool dfs(vector<vector<char>> &board, string &word, int pos, int i, int j);
    // 两棵二叉搜索树中的所有元素
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2);
    void dfs(TreeNode *root, vector<int> &arr);
    void insertSort(vector<int> &arr);
    // 机器人的运动范围(回溯)
    int movingCount(int m, int n, int k);
private:
    int count;
    void dfs(int i, int j, int &m, int &n, int &k, vector<vector<bool>> &flag);
    int GetSum(int i, int j);
    // 矩阵中的幸运数
    vector<int> luckyNumbers(vector<vector<int>> &matrix);
    // 全排列
    vector<string> permutation(string s);
private:
    vector<string> ans;
    void dfs(string &s, int index);
    // 实现strStr()函数
    int strStr(string haystack, string needle);
};

#endif //ALGORITHM_SOLUTION_H
