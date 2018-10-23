/*
LeetCode 33. 搜索旋转排序数组 https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/

题目描述：
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。

    ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

    搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

    你可以假设数组中不存在重复的元素。

    你的算法时间复杂度必须是 O(log n) 级别。

    示例 1:
        输入: nums = [4,5,6,7,0,1,2], target = 0
        输出: 4
    示例 2:
        输入: nums = [4,5,6,7,0,1,2], target = 3
        输出: -1

思路：
    虽然可能通过各种条件判断直接一次二分，但是很容易出错

    保险的做法是通过两次二分，先找出最小值的位置，然后确定 target 的区间，再用一次二分去找
    > 寻找最小值的位置 > LeetCode 153、154

提交记录：
    提交了 N 次才过，边界条件太容易出错了
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto n = nums.size();
        if (n < 1) return -1;

        auto lo = -1;
        auto hi = n - 1;
        while (lo + 1 < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi])
                lo = mid;
            else
                hi = mid;
        }
        if (target == nums[hi]) return hi;

        if (target > nums[hi] && target <= nums[n - 1]) {
            lo = hi;
            hi = n - 1;
        }
        else {
            lo = -1;
        }
        while (lo + 1 < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (target > nums[mid])
                lo = mid;
            else
                hi = mid;
        }
        return nums[hi] == target ? hi : -1;
    }
};

void
solve()
{
    vector<int> nums{ 3,5,1 };
    Solution().search(nums, 5);
}