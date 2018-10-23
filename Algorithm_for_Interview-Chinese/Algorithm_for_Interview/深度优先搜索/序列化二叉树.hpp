/*
序列化二叉树 https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

**题目描述**
    ```
    请实现两个函数，分别用来序列化和反序列化二叉树。
    接口如下：
      char* Serialize(TreeNode *root);
      TreeNode* Deserialize(char *str);
    ```
    - 比如中序遍历就是一个二叉树序列化
    - 反序列化要求能够通过序列化的结果还原二叉树
    - 空节点用 '#' 表示，节点之间用空格分开

**思路**
    - 一般在做树的遍历时，会以非空叶子节点作为最底层，此时还原二叉树必须要前序遍历+中序遍历或后序遍历
    - 如果以空节点作为树的最底层，那么只需要前序遍历就能还原二叉树，而且能与反序列化同步进行（这是最关键的一点）
*/
#pragma once

#include "../all.h"

class Solution {
    // 因为接口限制，所以需要使用了两个 ss
    stringstream ss_fw;
    stringstream ss_bw;
    char ret[1024];
    //char* ret;

    void dfs_s(TreeNode *node) {
        if (node == nullptr) {
            ss_fw << "#";
            return;
        }
        ss_fw << node->val;
        ss_fw << " ";
        dfs_s(node->left);
        ss_fw << " ";
        dfs_s(node->right);
    }

    TreeNode* dfs_d() {
        if (ss_bw.eof())
            return nullptr;
        string val;            // 只能用 string 接收，用 int 或 char 都会有问题
        ss_bw >> val;
        if (val == "#")
            return nullptr;
        TreeNode* node = new TreeNode{ stoi(val) }; // 
        node->left = dfs_d();
        node->right = dfs_d();
        return node;
    }

public:
    char* Serialize(TreeNode *root) {
        dfs_s(root);
        // 这里耗了很久
        // return (char*)ss.str().c_str();  // 会出问题，原因未知
        return strcpy(ret, ss_fw.str().c_str());
    }

    TreeNode* Deserialize(char *str) {
        if (strlen(str) < 1) return nullptr;
        ss_bw << str;
        return dfs_d();
    }
};

void
solve()
{
    TreeNode n1{ 1 };
    TreeNode n2{ 2 };
    TreeNode n3{ 3 };
    TreeNode n4{ 4 };
    TreeNode n5{ 5 };
    TreeNode n6{ 6 };
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    //solve();
    Solution s;
    auto ret = s.Serialize(&n1);
    cout << ret;
    //cout << s.Serialize(&n1) << endl;

    auto root = s.Deserialize(ret);
    cout << root->val;
}

