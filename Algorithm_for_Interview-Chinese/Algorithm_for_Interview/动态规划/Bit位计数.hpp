/*
LeetCode 338. Bit位计数 https://leetcode-cn.com/problems/counting-bits/description/

题目描述：
    给定一个非负整数 num。 对于范围 0 ≤ i ≤ num 中的每个数字 i ，计算其二进制数中的1的数目并将它们作为数组返回。
    示例：
        比如给定 num = 5 ，应该返回 [0,1,1,2,1,2].

要求：
    在线性时间O(n)内用一次遍历做到，空间复杂度为O(n)
    不使用语言的内置函数

思路：
    动态规划
*/
#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);   // 注意：& 运算符的优先级低于 +
        }

        return dp;
    }

    // pass
    vector<int> countBits_my(int num) {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            if (i & 1)  // i 为奇数
                dp[i] = dp[i - 1] + 1;
            else {      // i 为偶数
                int j = 0;
                int k = i - 1;
                while (k & 1) {
                    k >>= 1;
                    j++;
                }
                dp[i] = dp[i - 1] - j + 1;
            }
        }

        return dp;
    }
};