/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
;

ListNode *findMidNode(ListNode *first, ListNode *second) {
    ListNode *tail = first, *head = first;

    while ( head != second ) {
        head = head->next;
        if ( head == second ) {
            break;
        }
        head = head->next;
        tail = tail->next;
    }

    return tail;
}

TreeNode *convertTree(ListNode *first, ListNode *second) {
    ListNode *mid = findMidNode(first, second);
    if ( first == second ) {
        return nullptr;
    } 
    TreeNode *root = new TreeNode( mid->val );
    root->left = convertTree( first, mid );
    root->right = convertTree( mid->next, second );
    return root;
}


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return convertTree(head, nullptr);
    }
};
// @lc code=end
























