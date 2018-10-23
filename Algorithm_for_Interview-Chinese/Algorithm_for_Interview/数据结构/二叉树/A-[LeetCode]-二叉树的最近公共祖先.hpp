#pragma once

#include "../binary_tree.hpp"
#include <deque>
using namespace std;

// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
class Solution {
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

public:
    TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        deque<TreeNode*> path_p;
        auto found_p = getPath(root, p, path_p);
        deque<TreeNode*> path_q;
        auto found_q = getPath(root, q, path_q);

        TreeNode* ret = root;
        if (found_p && found_q) {
            auto it_p = path_p.begin();
            auto it_q = path_q.begin();

            while (it_p != path_p.end() && it_q != path_q.end()) {
                if (*it_p != *it_q)
                    return ret;

                ret = *it_p;
                it_p++, it_q++;
            }
            return ret;
        }

        return nullptr;
    }
};

void 
solve() {

    string line = "[3,5,1,6,2,0,8,null,null,7,4]";
    auto root = stringToTreeNode(line);
    //prettyPrintTree(root);

    auto p = root->left;
    auto q = root->right;

    auto ret = Solution().lowestCommonAncestor(root, p, q);

    cout << ret->val;
}