/*
最长公共子串_牛客网 https://www.nowcoder.com/questionTerminal/02e7cc263f8a49e8b1e1dc9c116f7602
*/
#pragma once

#include "../all.h"


class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        // 已经初始化为全 0，就不必再手动初始化 DP 了

        int ret = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = max(ret, dp[i][j]);
                }
                else
                    ;

        return ret;
    }

    int findLongest2(string A, int n, string B, int m) {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tmp_ret = 0;
                if (A[i] == B[j]) {
                    tmp_ret += 1;
                    int tmp_i = i + 1;
                    int tmp_j = j + 1;
                    while (tmp_i < n && tmp_j < m && A[tmp_i++] == B[tmp_j++])
                        tmp_ret++;
                }
                ret = max(ret, tmp_ret);
            }
        }
        
        return ret;
    }

    int findLongest3(string A, int n, string B, int m) {
        if (n < m) {
            swap(n, m);
            swap(A, B);
        }

        vector<int> dp(m, 0);
        
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (A[i] != B[j]) {
                    dp[j] = 0;
                }
                else {
                    if (i != 0) {
                        dp[j] = dp[j - 1] + 1;
                    }
                    else {
                        dp[j] = 1;
                    }
                }
                ret = max(ret, dp[j]);
            }
        }

        return ret;
    }

    int findLongest4(string A, int n, string B, int m) {
        int ret = 0;

        for (int row = 0, col = m - 1; row < n;) {
            int i = row;
            int j = col;
            int dp = 0;
            while (i < n && j < m) {
                if (A[i++] == B[j++])  // 注意：无论走哪个分支，i 和 j 都会 ++ 一次
                    dp += 1;
                else
                    dp = 0;

                ret = max(ret, dp);
            }

            if (col > 0) 
                col--;
            else 
                row++;
        }

        return ret;
    }

    int findLongest5(string A, int n, string B, int m) {
        int ret = 0;
        int dp;

        for (int col = m-1; col >= 0; col--) {
            dp = 0;
            for (int i = 0, j = col; i < n && j < m; i++, j++) {
                if (A[i] == B[j])
                    dp += 1;
                else
                    dp = 0;

                ret = max(ret, dp);
            }
        }

        for (int row = 0; row < n; row++) {
            dp = 0;
            for (int i = row, j = 0; i < n && j < m; i++, j++) {
                if (A[i] == B[j])
                    dp += 1;
                else
                    dp = 0;

                ret = max(ret, dp);
            }
        }

        return ret;
    }
};

void solve() {
    //auto ret = LongestSubstring().findLongest3("1AB2345CD", 9, "12345EF", 7);
    auto ret = LongestSubstring().findLongest5("1AB2345CD", 9, "12345EF", 7);
    print(ret);
}