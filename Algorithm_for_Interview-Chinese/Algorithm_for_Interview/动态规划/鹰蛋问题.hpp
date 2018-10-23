/*
Power Eggs http://acm.zcmu.edu.cn/JudgeOnline/problem.php?id=1894
*/
#pragma once

#include <cstdio>

typedef long long LL;

const int MAX_K = 32 + 1;
const int MAX_T = 32 + 1;
LL dp[MAX_K][MAX_T];          // 使用 LL 防止溢出，long 不保证比 int 更大
// dp[i][j] := i 个蛋比较 j 次所能确定的最高楼层

void init() {
    for (int i = 1; i < MAX_K; i++)
        dp[i][1] = 1;
    for (int j = 1; j < MAX_T; j++)
        dp[1][j] = j;

    for (int i = 2; i < MAX_K; i++)
        for (int j = 2; j < MAX_T; j++)
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] + 1;
}

void solve() {
    init();
    //printf("%lld", dp[32][32]);  // 4294967295 == 2^32 - 1，用 int 会溢出

    int T;          // 1 ≤ T ≤ 10000
    scanf("%d", &T);
    while (T--) {
        int N, K;   // 1 ≤ N ≤ 2000000007 < 2^31, 1 ≤ K ≤ 32
        scanf("%d %d", &N, &K);
        int ret = 0;
        for (int j = 1; j < MAX_T; j++) {
            if (dp[K][j] >= N) {
                ret = j;
                break;
            }
        }

        if (ret) printf("%d\n", ret);
        else puts("Impossible");
    }
}

//int main() {
//    solve();
//    return 0;
//}
