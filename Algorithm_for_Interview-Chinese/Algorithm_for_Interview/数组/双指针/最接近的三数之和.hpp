/*
最接近的三数之和 LeetCode https://leetcode-cn.com/problems/3sum-closest/description/
*/
#pragma once

#include "../../all.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());

        auto ret = nums[0] + nums[1] + nums[2];
        for (int i = 0; i <= nums.size()-3; i++) {
            int lo = i + 1;
            int hi = nums.size() - 1;
            while (lo < hi) {
                auto sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(target - ret)) {
                    ret = sum;
                    if (ret == target)
                        return ret;
                }
                sum > target ? hi-- : lo++;
            }
        }
        return ret;
    }
};

void solve() {


}