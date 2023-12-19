//
// Created by Messi on 2023/12/6.
//

#include <algorithm>
#include <queue>
#include "tree.h"

vector<int> tree::preorderTraversal(TreeNode *root) {
    std::vector<int> num;
    if (root == nullptr)
        return num;
    preOrder(root, num);
    return num;
}

vector<int> tree::preorderTraversal2(TreeNode *root) {
    std::vector<int> num;
    if (root != nullptr) {
        std::stack<TreeNode *> NodeStack;
        TreeNode *node = root;
        NodeStack.push(node);
        while (!NodeStack.empty()) {
            node = NodeStack.top();
            NodeStack.pop();
            num.push_back(node->val);
            /*先压右子树，再压左子树*/
            if (node->right != nullptr)
                NodeStack.push(node->right);
            if (node->left != nullptr)
                NodeStack.push(node->left);
        }
    }
    return num;
}

vector<int> tree::inorderTraversal(TreeNode *root) {
    std::vector<int> num;
    if (root == nullptr)
        return num;
    inOrder(root, num);
    return num;
}

vector<int> tree::inorderTraversal2(TreeNode *root) {
    std::vector<int> num;
    if (root != nullptr) {
        std::stack<TreeNode *> NodeStack;
        TreeNode *node = root;
        /* 栈不为空或者树还没有遍历完 */
        while (!NodeStack.empty() || node != nullptr) {
            if (node != nullptr) {
                NodeStack.push(node);
                node = node->left;
            } else {
                node = NodeStack.top();
                NodeStack.pop();
                num.push_back(node->val);
                /*处理右节点*/
                node = node->right;
            }
        }
    }
    return num;
}

vector<int> tree::postorderTraversal(TreeNode *root) {
    std::vector<int> num;
    if (root == nullptr)
        return num;
    postOrder(root, num);
    return num;
}

vector<int> tree::postorderTraversal2(TreeNode *root) {
    std::vector<int> num;
    if (root != nullptr) {
        std::stack<TreeNode *> NodeStack;
        TreeNode *node = root;
        NodeStack.push(node);
        while (!NodeStack.empty()) {
            node = NodeStack.top();
            NodeStack.pop();
            num.push_back(node->val);
            /*先压左节点*/
            if (node->left != nullptr)
                NodeStack.push(node->left);
            /*再压右节点*/
            if (node->right != nullptr)
                NodeStack.push(node->right);
        }
        std::reverse(num.begin(), num.end());
    }
    return num;
}

vector<vector<int>> tree::levelOrder(TreeNode *root) {
    std::vector<vector<int>> result;
    if (root == nullptr)
        return result;
    std::deque<TreeNode *> nodeQue;
    nodeQue.push_back(root);//根节点入队
    while (!nodeQue.empty()) {
        std::vector<int> temp;
        int len = nodeQue.size(); /*必须在for循环外边获取len，因为for里面会对队列加入新的节点，改变len*/
        for (int i = 0; i < len; i++) {
            /*取出元素，放入列表*/
            TreeNode *node = nodeQue.front();
            nodeQue.pop_front();
            temp.push_back(node->val);
            /*处理下一层节点*/
            if (node->left != nullptr)
                nodeQue.push_back(node->left);
            if (node->right != nullptr)
                nodeQue.push_back(node->right);
        }
        /*每一层结束之后把上一层的列表加入返回列表中*/
        result.push_back(temp);
    }
    return result;
}

void tree::preOrder(TreeNode *node, vector<int> &num) {
    if (node == nullptr)
        return;
    /*插入根，然后分别深入左和右*/
    num.push_back(node->val);
    preOrder(node->left, num);
    preOrder(node->right, num);
}

void tree::inOrder(TreeNode *node, vector<int> &num) {
    if (node == nullptr)
        return;
    inOrder(node->left, num);
    num.push_back(node->val);
    inOrder(node->right, num);
}

void tree::postOrder(TreeNode *node, vector<int> &num) {
    if (node == nullptr)
        return;
    postOrder(node->left, num);
    postOrder(node->right, num);
    num.push_back(node->val);
}

string Codec::serialize(TreeNode *root) {
    /* 空节点用‘#’代替，节点之间用‘,’分隔 */
    string ans = "";
    if (root == nullptr)
        return "#";
    /* bfs */
    std::queue<TreeNode *> nodeQue;
    nodeQue.push(root);
    while (!nodeQue.empty()) {
        int len = nodeQue.size();
        for (int i = 0; i < len; i++) {
            TreeNode *node = nodeQue.front();
            nodeQue.pop();
            if (node == nullptr) {
                ans += "#,";
                continue;
            }
            ans += std::to_string(node->val);
            ans += ",";
            /* 下一层入队 */
            nodeQue.push(node->left);
            nodeQue.push(node->right);
        }
    }
    return ans;
}

TreeNode *Codec::deserialize(string data) {
    if (data == "#")
        return nullptr;
    /* 去除‘,’ 由于二叉树中可能有节点数值大于9或为负数，所以不能直接遍历string*/
    vector<string> realData;
    string temp = "";
    for (auto i: data) {
        if (i == ',') {
            realData.push_back(temp);
            temp.clear();
            temp = "";
        } else
            temp += i;
    }
    /* deserialize */
    TreeNode *root = new TreeNode(std::atoi(realData[0].c_str()));
    std::queue<TreeNode *> nodeQue;
    nodeQue.push(root);
    for (int i = 1; i < realData.size(); i++) {
        /* 每个节点都做一次父节点，构造局部二叉树 */
        TreeNode *parent = nodeQue.front();
        nodeQue.pop();
        /* 每次取两个 */
        if (realData[i] != "#") {
            TreeNode *left = new TreeNode(std::atoi(realData[i].c_str()));
            parent->left = left;
            nodeQue.push(left);
        }
        if (realData[++i] != "#") {
            TreeNode *right = new TreeNode(std::atoi(realData[i].c_str()));
            parent->right = right;
            nodeQue.push(right);
        }
    }
    return root;
}

TreeNode *CreateTree::buildTree_1(vector<int> &preorder, vector<int> &inorder) {
    vector<int> leftorder, rightorder;
    int R = preorder[0];
    int i;
    for (i = 0; i < inorder.size(); i++) {
        if (inorder[i] == R)
            break;
        leftorder.push_back(inorder[i]);
    }
    for (i += 1; i < inorder.size(); i++) {
        rightorder.push_back(inorder[i]);
    }
}

TreeNode *CreateTree::buildTree_2(vector<int> &preorder, vector<int> &postorder) {

}

void ThreadTree::CreatePreThreadTree(ThreadTreeNode *root) {
    if (root == nullptr)
        return;
    pre = nullptr;
    preOrderThreadTree(root);
    if (pre->right == nullptr)
        pre->rtag = 1;//将最后一个节点设为线索
}

void ThreadTree::preOrderThreadTree(ThreadTreeNode *root) {
    if (root == nullptr)
        return;
    visit(root);
    if (root->ltag == 0)//左节点不是前驱线索(避免‘绕圈’)
        preOrderThreadTree(root->left);
    preOrderThreadTree(root->right);
}

void ThreadTree::CreateInThreadTree(ThreadTreeNode *root) {
    if (root == nullptr)
        return;
    pre = nullptr;
    inOrderThreadTree(root);
    if (pre->right == nullptr)
        pre->rtag = 1;//将最后一个节点设为线索
}

void ThreadTree::inOrderThreadTree(ThreadTreeNode *root) {
    if (root == nullptr)
        return;
    inOrderThreadTree(root->left);
    visit(root);
    inOrderThreadTree(root->right);
}

void ThreadTree::CreatePostThreadTree(ThreadTreeNode *root) {
    if (root == nullptr)
        return;
    pre = nullptr;
    postOrderThreadTree(root);
    if (pre->right == nullptr)
        pre->rtag = 1;//将最后一个节点设为线索
}

void ThreadTree::postOrderThreadTree(ThreadTreeNode *root) {
    if (root == nullptr)
        return;
    pre = nullptr;
    postOrderThreadTree(root->left);
    postOrderThreadTree(root->right);
    visit(root);
}

ThreadTreeNode *ThreadTree::FirstNode(ThreadTreeNode *root) {
    while (root->ltag == 0)
        root = root->left;
    return root;
}

ThreadTreeNode *ThreadTree::NextNode(ThreadTreeNode *node) {
    if (node->rtag == 0)
        return FirstNode(node); //node的右子树中最先被中序遍历的节点(最左下节点)
    return node->right;
}

void ThreadTree::Inorder(ThreadTreeNode *root, vector<int> &nums) {
    for (ThreadTreeNode *node = FirstNode(root); node != nullptr; node = NextNode(node))
        nums.push_back(node->val);
}

void ThreadTree::visit(ThreadTreeNode *node) {
    if (node->left == nullptr) {
        node->left = pre;
        node->ltag = 1;
    }
    if (pre != nullptr && pre->right == nullptr) {
        pre->right = node;
        pre->right->rtag = 1;
    }
    pre = node;
}

ThreadTreeNode *ThreadTree::LastNode(ThreadTreeNode *root) {
    while (root->rtag == 0)
        root = root->right;
    return root;
}

ThreadTreeNode *ThreadTree::PreNode(ThreadTreeNode *node) {
    if (node->ltag == 0)
        return LastNode(node->left); //node的左子树种最后被中序遍历的节点(最右下节点)
    return node->left;
}

void ThreadTree::RevInorder(ThreadTreeNode *root, vector<int> &nums) {
    for (ThreadTreeNode *node = LastNode(root); node != nullptr; node = PreNode(node))
        nums.push_back(node->val);
}
