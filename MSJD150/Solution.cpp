//
// Created by Messi on 2023/12/6.
//

#include "Solution.h"
#include <map>
#include <unordered_map>
#include <unordered_set>
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


void help_invertTree(TreeNode *root, TreeNode *src) {
    if (src == nullptr) {
        return;
    }
    root = new(TreeNode);
    root->val = src->val;
    // 右
    help_invertTree(root->left, src->right);
    // 左
    help_invertTree(root->right, src->left);
}

TreeNode *Solution::invertTree(TreeNode *root) {
    // 前序遍历并交换左右子树
    if (root == nullptr) {
        return root;
    }

    TreeNode *node = root->right;
    root->right = root->left;
    root->left = node;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

TreeNode *Solution::lowestCommonAncestor_2(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor_2(root->left, p, q);
    TreeNode *right = lowestCommonAncestor_2(root->right, p, q);
    if (left == nullptr && right == nullptr)
        return nullptr;
    else if (left == nullptr && right != nullptr)
        return right;
    else if (left != nullptr && right == nullptr)
        return left;
    return root;
}

TreeNode *Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    while (root != nullptr) {
        if (p->val > root->val && q->val > root->val)
            root = root->right;
        else if (p->val < root->val && q->val < root->val)
            root = root->left;
        else
            break;
    }
    return root;
}

int Solution::kthLargest(TreeNode *root, int k) {
    std::stack<TreeNode *> Nodestack;
    while (!Nodestack.empty() || root != nullptr) {
        while (root != nullptr) {
            Nodestack.push(root);
            root = root->right;
        }
        if (!Nodestack.empty()) {
            root = Nodestack.top();
            Nodestack.pop();
            if (k == 1)
                return root->val;
            root = root->left;
            k--;
        }
    }
    return 0;
}

int Solution::GetSum(int i, int j) {
    int sum = 0;
    while (i != 0) {
        sum += i % 10;
        i /= 10;
    }
    while (j != 0) {
        sum += j % 10;
        j /= 10;
    }
    return sum;
}

void Solution::dfs(int i, int j, int &m, int &n, int &k, vector<vector<bool>> &flag) {
    if (i < 0 || i >= m || j < 0 || j >= n || flag[i][j] || GetSum(i, j) > k)
        return;
    else if (GetSum(i, j) <= k)
        count++;
    flag[i][j] = true;
    dfs(i - 1, j, m, n, k, flag);
    dfs(i + 1, j, m, n, k, flag);
    dfs(i, j - 1, m, n, k, flag);
    dfs(i, j + 1, m, n, k, flag);
    /*回溯的时候不能把flag复位，因为题目是计算格子数，而不是计算路径数*/
}

void Solution::insertSort(vector<int> &arr) {
    int len = arr.size();
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Solution::dfs(TreeNode *root, vector<int> &arr) {
    if (root == nullptr)
        return;
    std::stack<TreeNode *> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        TreeNode *node = nodeStack.top();
        nodeStack.pop();
        arr.push_back(node->val);
        if (node->right != nullptr)
            nodeStack.push(node->right);
        if (node->left != nullptr)
            nodeStack.push(node->left);
    }
}

vector<int> Solution::getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> ans;
    dfs(root1, ans);
    dfs(root2, ans);
    insertSort(ans);
    return ans;
}

bool Solution::dfs(vector<vector<char>> &board, string &word, int pos, int i, int j) {
    /* 剪枝 */
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[pos])
        return false;
    if (board[i][j] == word[pos] && pos == word.size() - 1)
        return true;
    board[i][j] = '\0';
    bool res = dfs(board, word, pos + 1, i - 1, j) || dfs(board, word, pos + 1, i, j - 1) ||
               dfs(board, word, pos + 1, i + 1, j) || dfs(board, word, pos + 1, i, j + 1);
    board[i][j] = word[pos];
    return res;
}

bool Solution::exist(vector<vector<char>> &board, string word) {
    /* dfs+剪枝 */
    int rows = board.size();
    int cols = board[0].size();
    /* 每个格子都做一次起点开启dfs */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dfs(board, word, 0, i, j))
                return true;
        }
    }
    return dfs(board, word, 0, 0, 0);
}

vector<int> Solution::luckyNumbers(vector<vector<int>> &matrix) {
    vector<int> rowMinlist;
    vector<int> colMaxlist;
    /*找每一行的最小元素*/
    for (int i = 0; i < matrix.size(); i++) {
        int min = matrix[i][0];
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
        rowMinlist.push_back(min);
    }
    /*找每一列的最大元素*/
    for (int i = 0; i < matrix[0].size(); i++) {
        int max = matrix[0][i];
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[j][i] > max)
                max = matrix[j][i];
        }
        colMaxlist.push_back(max);
    }
    /*找公共元素*/
    vector<int> ans;
    for (int i: rowMinlist) {
        for (int j: colMaxlist) {
            if (i == j)
                ans.push_back(i);
        }
    }
    return ans;
}

vector<string> Solution::permutation(string s) {
    dfs(s, 0);
    return ans;
}

void Solution::dfs(string &s, int index) {
    if (index == s.size() - 1) {
        ans.push_back(s);
        return;
    }
    std::set<char> set;
    for (int i = index; i < s.size(); i++) {
        if (set.find(s[i]) != set.end()) //剪枝
            continue;
        set.insert(s[i]);          //此位次字符已经使用过了
        std::swap(s[i], s[index]); //交换位
        dfs(s, index + 1);         //开启固定第 x + 1 位字符
        std::swap(s[i], s[index]); //复位
    }
}

int Solution::strStr(string haystack, string needle) {
    if (haystack.empty() || needle.empty() || haystack.size() < needle.size())
        return 0;
    int first = 0, second;
    while (first < haystack.size()) {
        second = 0;
        if (haystack[first] == needle[second]) {
            /*进入判断*/
            for (int i = first; i < haystack.size(); i++) {
                if (haystack[i] == needle[second]) {
                    if (second != needle.size() - 1) {
                        second++;
                    } else
                        return first;
                } else
                    break;
            }
        }
        first++;
    }
    return -1;
}

bool Solution::isIsomorphic(string s, string t) {
    if (s.size() != t.size())
        return false;
    std::unordered_map<char, char> Map;
    std::unordered_set<char> Set;
    for (int i = 0; i < s.size(); i++) {
        if (Map.count(s[i]) <= 0) {
            if (Set.count(t[i]) <= 0) { /*判断该值是否被映射过*/
                Map[s[i]] = t[i];
                Set.insert(t[i]);
            } else
                return false;
        } else {
            auto it = Map.find(s[i]);
            if (t[i] != it->second)
                return false;
        }
    }
    return true;
}

int Solution::movingCount(int m, int n, int k) {
    if (k <= 0)
        return 0;
    count = 1;
    vector<vector<bool>> flag(m, vector<bool>(n, true));
    dfs(0, 0, m, n, k, flag);
    return count;
}

bool Solution::isSymmetric(TreeNode *root) {

    return false;
}










