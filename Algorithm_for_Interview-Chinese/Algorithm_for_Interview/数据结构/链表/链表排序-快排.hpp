#pragma once

#include "../list.hpp"

#include <algorithm>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

// LeetCode 148. 排序链表 https://leetcode-cn.com/problems/sort-list/description/
class Solution {
    void qsort(ListNode* lo, ListNode* hi) {
        if (lo != hi && lo->next != hi) {  // 半开区间 [lo, hi)
            auto mid = partition(lo, hi);
            qsort(lo, mid);
            qsort(mid->next, hi);
        }
    }

    ListNode* partition(ListNode* lo, ListNode* hi) {
        int key = lo->val;  // 以 low 作为枢纽
        auto mid = lo;
        for (auto i = lo->next; i != hi; i = i->next) {
            if (i->val < key) {
                mid = mid->next;
                swap(i->val, mid->val);  // 交换节点内的值
            }
        }

        swap(lo->val, mid->val);         // 交换 low 与 mid

        return mid;
    }

public:
    ListNode * sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        qsort(head, nullptr);
        return head;
    }
};