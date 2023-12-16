#include <iostream>
#include "MSJD150/Solution.h"

int main() {
    Solution func;

    std::vector<int> nums{2, 1, 3};
    std::vector<int> nums1{1, 4, 4};
    std::vector<int> nums2{1, 1, 1, 1, 1, 1, 1, 1};
    std::string s("abcabcbb");

    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    func.invertTree(root);

    return 0;
}
