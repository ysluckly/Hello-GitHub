/*
二进制中1的个数 https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

时间限制：1秒 空间限制：32768K 热度指数：197271

思路：
    补码

*/
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "../all.h"

class Solution {
public:
    // 更快的方法
    int NumberOf1(int n) {
        int cnt = 0;

        while (n != 0) {
            cnt++;
            n = n & (n - 1);
        }

        return cnt;
    }

    // 直观的方法
    int NumberOf1_2(int n) {
        int cnt = 0;

        while (n != 0) {
            if (n & 1) cnt += 1;
            n >>= 1;
        }

        return cnt;
    }
};

void 
solve() {
    bitset<8> ns{ 127 };  // 不能用于 负数
    print(ns.count());
}
