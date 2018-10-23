/*
LeetCode 7. 反转整数 https://leetcode-cn.com/problems/reverse-integer/description/

题目描述：
    给定一个 32 位有符号整数，将整数中的数字进行反转。
    假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

    示例 1:
        输入: 123
        输出: 321
    示例 2:
        输入: -123
        输出: -321
    示例 3:
        输入: 120
        输出: 21

思路：
    求余，循环移位
    溢出判断
        if (new_res / 10 != res) return 0;
*/
#pragma once

class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x) {
            int d = x % 10;
            int new_res = res * 10 + d;
            if (new_res / 10 != res) 
                return 0;      // 溢出判断
            res = new_res;
            x /= 10;
        }

        return res;
    }
};