#pragma once

/*
LeetCode 838. 推多米诺 https://leetcode-cn.com/problems/push-dominoes/description/

招行 180831 笔试第二题

如果给原始输入左右分别加上一个 "L" 和 "R"，那么共有以下 4 种可能
'R......R' => 'RRRRRRRR'
'L......L' => 'LLLLLLLL'
'L......R' => 'L......R'
'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'

ref: https://leetcode.com/problems/push-dominoes/discuss/132332/C++JavaPython-Two-Pointers
*/

#include "../../all.h"

class Solution {
public:
    string pushDominoes(string d) {
        string s = "L" + d + "R";
        string ret = "";

        int lo = 0, hi = 1;
        for (; hi < s.length(); hi++) {
            if (s[hi] == '.')
                continue;

            if (lo > 0)         // 注意这一步操作
                ret += s[lo];

            int delta = hi - lo - 1;
            if (s[lo] == s[hi])
                ret += string(delta, s[lo]);  // string 的一种构造函数，以 s[lo] 为每个字符，生成长度为 h_l 的字符串
            else if (s[lo] == 'L' && s[hi] == 'R')
                ret += string(delta, '.');
            else if (s[lo] == 'R' && s[hi] == 'L')
                ret += string(delta / 2, 'R') + string(delta & 1, '.') + string(delta / 2, 'L');

            lo = hi;
        }

        return ret;
    }

};

void solve()
{
    string d{ ".L.R...LR..L.." };
    auto ret = Solution().pushDominoes(d);
    print(ret);
}