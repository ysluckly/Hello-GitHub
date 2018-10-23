/*
// NYOJ 311-完全背包: http://nyoj.top/problem/311
*/
#pragma once

// NYOJ 311-完全背包: http://nyoj.top/problem/311
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    const int inf = 0x3f3f3f3f;

    int T;
    scanf("%d", &T);
    while (T--) {
        int N, V;       // M 表示物品种类的数目，V 表示背包的总容量
        scanf("%d%d", &N, &V);
        vector<int> w(N + 1), v(N + 1);  // w 表示重量，v 表示价值
        for (int i = 1; i <= N; i++)
            scanf("%d%d", &w[i], &v[i]);

        vector<vector<int> > dp(N + 1, vector<int>(V + 1, -inf));
        for (int i = 0; i <= N; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= V; j++) {
                if (j < w[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
                //for (int k = 0; k*w[i] < j; k++)
                //    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }

        if (dp[N][V] > 0)
            printf("%d\n", dp[N][V]);
        else
            puts("NO");
    }
}


// NYOJ 311-完全背包: http://nyoj.top/problem/311
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// 一维 DP
void solve2() {
    const int MAX_V = 50000 + 10;
    const int inf = 0x3f3f3f3f;

    int T;
    scanf("%d", &T);
    while (T--) {
        int N, V;       // M 表示物品种类的数目，V 表示背包的总容量
        scanf("%d%d", &N, &V);
        //vector<int> w(N + 1), v(N + 1);  // w 表示重量，v 表示价值
        //for (int i = 1; i <= N; i++)
        //    scanf("%d%d", &w[i], &v[i]);

        //vector<int> dp(V + 1, inf);   // 注意 NYOJ 的系统开辟大的 vector 会导致超时
        int dp[MAX_V];
        fill(dp, dp + MAX_V, -inf);
        dp[0] = 0;

        for (int i = 1; i <= N; i++) {
            int w, v;
            scanf("%d%d", &w, &v);      // 避免开辟新的内存 
            for (int j = w; j <= V; j++) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }

        if (dp[V] > 0)
            printf("%d\n", dp[V]);
        else
            puts("NO");
    }
}


// NYOJ 311-完全背包: http://nyoj.top/problem/311 （未通过测试，报运行时错误）
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve3() {
    const int MAX_V = 50000 + 10;
    const int inf = 0x3f3f3f3f;

    int T;
    scanf("%d", &T);
    while (T--) {
        int N, V;       // M 表示物品种类的数目，V 表示背包的总容量
        scanf("%d%d", &N, &V);
        //vector<int> w(N + 1), v(N + 1);  // w 表示重量，v 表示价值
        //for (int i = 1; i <= N; i++)
        //    scanf("%d%d", &w[i], &v[i]);

        //vector<vector<int> > dp(2, vector<int>(V + 1, -inf));
        int dp[2][MAX_V];
        for (int i = 0; i < 2; i++) {
            fill(dp[i], dp[i] + MAX_V, -inf);
            dp[i][0] = 0;
        }

        for (int i = 1; i <= N; i++) {
            int w, v;
            scanf("%d%d", &w, &v);
            for (int j = 0; j <= V; j++) {
                if (j < w)
                    dp[i & 1][j] = dp[(i - 1) & 1][j];
                else
                    dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j - w] + v);
            }
        }

        if (dp[N][V] > 0)
            printf("%d\n", dp[N & 1][V]);
        else
            puts("NO");
    }
}

//int main() {
//    solve3();
//    return 0;
//}