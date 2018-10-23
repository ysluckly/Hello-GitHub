#pragma once

#include "../binary_tree.hpp"

bool getPath(TreeNode* root, TreeNode* p, deque<TreeNode*>& path) {
    if (root == nullptr)
        return false;

    path.push_back(root);
    if (p == root)
        return true;

    bool found = false;
    if (!found)
        found = getPath(root->left, p, path);
    if (!found)
        found = getPath(root->right, p, path);

    if (!found)
        path.pop_back();

    return found;
}

/* 非二叉树版本

struct TreeNode {
    int                       val;    
    std::vector<TreeNode*>    children;    
};

bool getPath(const TreeNode* root, const TreeNode* p, deque<const TreeNode*>& path) {
    if (root == nullptr)
        return false;

    path.push_back(root);
    if (root == p)
        return true;

    bool found = false;
    auto i = root->children.begin();            // 顺序遍历每个子节点
    while (!found && i < root->children.end()) {
        found = GetNodePath(*i, p, path);
        ++i;
    }

    if (!found)  // 如果没有找到就，说明当前节点不在路径内，弹出
        path.pop_back();

    return found;
}
*/
