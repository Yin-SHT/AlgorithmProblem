/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *findMidNode( ListNode *head ) {
        ListNode *slow = head, *quick = head->next;
        while ( quick != nullptr && quick->next != nullptr ) {
            slow = slow->next;
            quick = quick->next->next;
        }
        return slow;
    }

    ListNode *mergeTwoList( ListNode *left, ListNode *right ) {
        ListNode *sentry = new ListNode(), *move = sentry;
        while ( left != nullptr && right != nullptr ) {
            if ( left->val < right->val ) {
                move->next = left;
                left = left->next;                
            } else {
                move->next = right;
                right = right->next;
            }
            move = move->next;
        }
        move->next = left != nullptr ? left : right;
        return sentry->next;
    }

    ListNode* sortList( ListNode *head ) {
        if ( head == nullptr || head->next == nullptr ) {
            return head;
        }
        ListNode *mid = findMidNode( head );
        ListNode *rightHead = mid->next;
        mid->next = nullptr;
        ListNode *left = sortList( head );
        ListNode *right = sortList ( rightHead );
        return mergeTwoList( left, right );
    }
};
// @lc code=end























