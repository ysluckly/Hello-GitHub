#pragma once

/*
LeetCode 124. 二叉树中的最大路径和 https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/

知识点：DFS; 树DP
*/

#include "../binary_tree.hpp"

//class Solution {
//    const int inf = 0x3f3f3f3f;
//    int max_ret = -inf;
//
//    int maxDeep(TreeNode* root) {
//        if (!root) return 0;
//
//        return max(0, root->val + max({ 0, maxDeep(root->left), maxDeep(root->right) }));
//    }
//public:
//    int maxPathSum(TreeNode* root) {
//        if (root == nullptr) return -inf;
//
//        int path_sum = root->val + maxDeep(root->right) + maxDeep(root->left);
//
//        return max({ path_sum, maxPathSum(root->left), maxPathSum(root->right) });
//    }
//};

class Solution {
    // C++11 支持 就地 初始化
    const int inf = 0x3f3f3f3f;
    int ret = -inf;

    int maxDeepSum(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int l_sum = max(0, maxDeepSum(node->left));
        int r_sum = max(0, maxDeepSum(node->right));

        ret = max(ret, node->val + l_sum + r_sum);
        return node->val + max(l_sum, r_sum);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxDeepSum(root);
        return ret;
    }
};

void solve()
{
    string input{ "[1,null,2,null,3,null,4,null,5]" };
    auto root = stringToTreeNode(input);

    Solution().maxPathSum(root);
}
