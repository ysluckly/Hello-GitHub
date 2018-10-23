/*
三数之和 LeetCode https://leetcode.com/problems/3sum/description/
*/
#pragma once

#include "../../all.h"


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();  // 输入数量小于 3 直接退出

        sort(nums.begin(), nums.end());                     // 排序

        vector<vector<int>> ret;
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // 跳过第一个数相同的情况

            int target = -nums[i];
            int lo = i + 1;
            int hi = nums.size() - 1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] < target)
                    lo++;
                else if (nums[lo] + nums[hi] > target)
                    hi--;
                else {
                    ret.push_back({ nums[i], nums[lo], nums[hi] });
                    lo++, hi--;

                    while (lo < hi && nums[lo] == nums[lo - 1]) lo++;   // 跳过第二个数相同的情况
                    while (lo < hi && nums[hi] == nums[hi + 1]) hi--;   // 跳过第三个数相同的情况
                }
            }
        }
        return ret;
    }
};

void
solve()
{
    vector<int> nums{ -1,0,1,2,-1,-4 };
    auto ret = Solution().threeSum(nums);
}