/*
最长递增子序列_牛客网 https://www.nowcoder.com/questionTerminal/585d46a1447b4064b749f08c2ab9ce66
*/
#pragma once

#include "../all.h"

class AscentSequence1 {
public:
    int findLongest(vector<int> nums, int n) {
        vector<int> dp(n, 1);

        int ret = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;

            ret = max(ret, dp[i]);
        }

        return ret;
    }
};

class AscentSequence {
public:
    int findLongest(const vector<int>& nums, int n) {
        vector<int> dp;

        for (int j = 0; j < n; j++) {
            auto it = upper_bound(dp.begin(), dp.end(), nums[j]);
            if (it == dp.end())
                dp.push_back(nums[j]);
            else
                *it = nums[j];
        }

        return dp.size();
    }
};

void
solve() {
    auto ret = AscentSequence().findLongest({ 203,39,186,207,83,80,89,237,247 }, 9);
    print(ret);
}