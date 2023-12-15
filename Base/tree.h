//
// Created by Messi on 2023/12/6.
//

#ifndef ALGORITHM_TREE_H
#define ALGORITHM_TREE_H

#include <iostream>
#include <vector>
#include <stack>
#include "source.h"

using namespace std;


// 二叉树
class tree {
    // 二叉树遍历
public:
    /*前序遍历递归法*/
    vector<int> preorderTraversal(TreeNode *root);

    /*前序遍历迭代法 -- 栈辅助*/
    vector<int> preorderTraversal2(TreeNode *root);

    /*中序遍历递归法*/
    vector<int> inorderTraversal(TreeNode *root);

    /*中序遍历迭代法*/
    vector<int> inorderTraversal2(TreeNode *root);

    /*后序遍历递归*/
    vector<int> postorderTraversal(TreeNode *root);

    /*后序遍历迭代*/
    vector<int> postorderTraversal2(TreeNode *root);

    /*层序遍历*/
    vector<vector<int>> levelOrder(TreeNode *root);

private:
    static void preOrder(TreeNode *node, std::vector<int> &num);

    static void inOrder(TreeNode *node, std::vector<int> &num);

    static void postOrder(TreeNode *node, std::vector<int> &num);
};

/* 二叉树编码与解码 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root);

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data);
};

/* 由遍历序列构造二叉树 */
class CreateTree {
public:
    /* 中序+前序 */
    TreeNode *buildTree_1(vector<int> &preorder, vector<int> &inorder);

    /* 中序+后序 */
    TreeNode *buildTree_2(vector<int> &preorder, vector<int> &postorder);
};

/* 线索二叉树 */
class ThreadTree {
public:
    /*先序线索*/
    void CreatePreThreadTree(ThreadTreeNode *root);

    void preOrderThreadTree(ThreadTreeNode *root);

    /*中序线索*/
    void CreateInThreadTree(ThreadTreeNode *root);

    void inOrderThreadTree(ThreadTreeNode *root);

    /*后续线索*/
    void CreatePostThreadTree(ThreadTreeNode *root);

    void postOrderThreadTree(ThreadTreeNode *root);

    /**中序**/
    /*找到以中序遍历中第一个被遍历的节点*/
    ThreadTreeNode *FirstNode(ThreadTreeNode *root);

    /*找到node节点的中序后继节点*/
    ThreadTreeNode *NextNode(ThreadTreeNode *node);

    /*利用中序线索二叉树进行中序遍历  非递归*/
    void Inorder(ThreadTreeNode *root, vector<int> &nums);

    /*找到以中序遍历中最后一个被遍历的节点*/
    ThreadTreeNode *LastNode(ThreadTreeNode *root);

    /*找到node节点的中序前驱节点*/
    ThreadTreeNode *PreNode(ThreadTreeNode *node);

    /*利用中序线索二叉树进行逆中序遍历  非递归*/
    void RevInorder(ThreadTreeNode *root, vector<int> &nums);

private:
    /*添加线索*/
    void visit(ThreadTreeNode *node);

    ThreadTreeNode *pre = nullptr;
};

#endif //ALGORITHM_TREE_H
