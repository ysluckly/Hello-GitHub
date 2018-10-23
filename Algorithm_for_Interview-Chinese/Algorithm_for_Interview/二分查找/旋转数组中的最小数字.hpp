/*
剑指Offer：旋转数组的最小数字 https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
LeetCode 153. 寻找旋转排序数组中的最小值（不重复） https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
LeetCode 154. 寻找旋转排序数组中的最小值 II（可重复） https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

题目描述
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。

    ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

    请找出其中最小的元素。

    无论数组中是否存在重复元素，都可以使用以下代码

思路：
    二分查找，具体看代码
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        auto n = nums.size();
        if (n < 1) return 0;

        int lo = -1;
        int hi = n - 1;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] < nums[hi])           // 因为设计 lo 是作为开区间，因此与 nums[hi] 比较
                hi = mid;
            else if (nums[mid] > nums[hi])
                lo = mid;
            else
                hi--;                           // 处理重复元素
        }

        return nums[lo + 1];
    }
};


void solve() {
    vector<int> nums{ 2, 1 };
    int ret = Solution().findMin(nums);
    print(ret);
}
