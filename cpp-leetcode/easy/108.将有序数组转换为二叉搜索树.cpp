/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
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
#include <vector>

TreeNode* arrayToTree(std::vector<int> &nums, int i, int j) {
    if (i > j) return nullptr;
    int mid = (i + j) / 2;
    TreeNode *root = new TreeNode;
    root->val = nums[mid];
    root->left = arrayToTree(nums, i, mid - 1);
    root->right = arrayToTree(nums, mid + 1, j);
    return root;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return arrayToTree(nums, 0, nums.size() - 1);
    }
};
// @lc code=end




















