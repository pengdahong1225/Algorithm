//
// Created by Messi on 2023/12/6.
//

#include "Solution.h"
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
#include <queue>

void Solution::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    // 双指针
    std::vector<int> ret;
    int p1 = 0, p2 = 0;
    while (p1 < m && p2 < n) {
        if (nums1[p1] <= nums2[p2]) {
            ret.emplace_back(nums1[p1]);
            p1++;
        } else {
            ret.emplace_back(nums2[p2]);
            p2++;
        }
    }
    while (p1 < m) {
        ret.emplace_back(nums1[p1]);
        p1++;
    }
    while (p2 < n) {
        ret.emplace_back(nums2[p2]);
        p2++;
    }
    std::swap(nums1, ret);
}

int Solution::removeElement(std::vector<int> &nums, int val) {
    // 双指针，头尾交换
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        if (nums[left] == val) {
            nums[left] = nums[right];
            right--;
        } else {
            left++;
        }
    }
    return left;
}

int Solution::removeDuplicates(std::vector<int> &nums) {
    // 双指针(快慢指针)
    if (nums.size() < 2) {
        return nums.size();
    }
    int left = 0, right = 1;
    while (right < nums.size()) {
        if (nums[left] == nums[right]) {
            right++;
        } else {
            // 发现不一样的元素，替换
            if (right - left > 0) {
                left++;
                nums[left] = nums[right];
            }
        }
    }
    return left + 1;
}

int Solution::removeDuplicates_2(std::vector<int> &nums) {
    // 双指针

    return 0;
}

int Solution::majorityElement(vector<int> &nums) {
    std::map<int, int> count;
    for (int num: nums) {
        count[num]++;
    }
    int ret = nums[0];
    for (const auto &it: count) {
        if (it.second > count[ret]) {
            ret = it.first;
        }
    }
    return ret;
}

void Solution::rotate(vector<int> &nums, int k) {
    std::vector<int> temp = nums;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        nums[(i + k) % len] = temp[i];
    }
}

int Solution::maxProfit(vector<int> &prices) {
    // 找到最小价格和最大利润 即可
    int min_price = prices[0], max_profit = 0;
    for (int price: prices) {
        if (price < min_price) {
            min_price = price;
        }
        if (price - min_price > max_profit) {
            max_profit = price - min_price;
        }
    }
    return max_profit;
}

int Solution::maxProfit_2(vector<int> &prices) {
    // 贪心 -- 第二天要跌就卖掉
    if (prices.size() < 2) {
        return 0;
    }
    int profit = 0;
    std::stack<int> temp_profit;
    for (int i = 1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i - 1];
        if (diff < 0) {
            // 卖
            int len = temp_profit.size();
            for (int j = 0; j < len; j++) {
                profit += temp_profit.top();
                temp_profit.pop();
            }
        } else {
            // 记录当日收益
            temp_profit.push(diff);
        }
    }
    // 最后检查是否还有没卖掉的
    int len = temp_profit.size();
    for (int j = 0; j < len; j++) {
        profit += temp_profit.top();
        temp_profit.pop();
    }
    return profit;
}

bool Solution::isPalindrome(string s) {
    // 双指针
    string sData = "";
    for (char r: s) {
        if ((r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z') || (r >= '0' && r <= '9')) {
            if (std::isupper(r))
                r = std::tolower(r);
            sData += r;
        }
    }
    if (sData.size() == 2)
        return sData[0] == sData[1] || sData[0] == sData[1] - 32;
    int left = 0, right = sData.size() - 1;
    while (left < right) {
        if (sData[left] != sData[right] && sData[left] != sData[right] - 32)
            return false;
        left++;
        right--;
    }
    return true;
}

bool Solution::isSubsequence(string s, string t) {
    // 双指针
    int p1 = 0, p2 = 0;
    while (p2 < t.size()) {
        if (p1 >= s.size()) {
            return true;
        }
        if (t[p2] == s[p1]) {
            p1++;
        }
        p2++;
    }
    if (p1 >= s.size()) {
        return true;
    }
    return false;
}

vector<int> Solution::twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size() - 1; i++) {
        int num = target - numbers[i];
        // 二分查找
        int left = i + 1, right = numbers.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (numbers[mid] == num) {
                return {i + 1, mid + 1};
            } else if (numbers[mid] > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return {};
}

int Solution::maxArea(vector<int> &height) {
    return 0;
}

int Solution::minSubArrayLen(int target, vector<int> &nums) {
    // 滑动窗口
    int length = nums.size() + 1;
    std::queue<int> queue_;
    int sum = 0;
    int i = 0;
    while (i < nums.size()) {
        queue_.push(nums[i]);
        sum += nums[i];
        while (sum >= target && !queue_.empty()) {
            length = queue_.size() < length ? queue_.size() : length;
            sum -= queue_.front();
            queue_.pop();
        }
        i++;
    }
    if (length == nums.size() + 1) {
        return 0;
    }
    return length;
}

int Solution::lengthOfLongestSubstring(string s) {
    // 滑动窗口
    if (s.size() < 2) {
        return s.size();
    }
    int ret = 0;
    std::queue<char> cache_;
    std::unordered_map<char, int> count_;
    for (int i = 0; i < s.size(); i++) {
        count_[s[i]]++;
        while (count_[s[i]] > 1) {
            char ch = cache_.front();
            cache_.pop();
            count_[ch]--;
        }
        cache_.push(s[i]);
        ret = cache_.size() > ret ? cache_.size() : ret;
        cout << s[i] << ret << endl;
    }
    return ret;
}

int Solution::maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool Solution::canJump(vector<int> &nums) {
    // 可以到达的最远位置，直接遍历
    int reach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > reach) {
            return false;
        }
        reach = max(i + nums[i], reach);
    }
    return true;
}

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p != nullptr && q != nullptr) {
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
    return false;
}

TreeNode *Solution::invertTree(TreeNode *root) {

    return nullptr;
}









