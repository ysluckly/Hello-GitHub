/*
LeetCode 190. 颠倒二进制位 https://leetcode-cn.com/problems/reverse-bits/description/

题目描述：
    颠倒给定的 32 位无符号整数的二进制位。

    示例:
        输入: 43261596
        输出: 964176192
        解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
        返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
*/
#pragma once

#include "../all.h"

class Solution {
public:

    // 硬编码 的递归形式
    uint32_t reverseBits(uint32_t n) {
        unsigned s = 8 * sizeof(n);
        uint32_t mask = ~0;
        while ((s >>= 1) > 0) {
            mask ^= mask << s;
            n = ((n >> s) & mask) | ((n << s) & (~mask));
        }
        return n;
    }

    // 硬编码
    uint32_t reverseBits_2(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};