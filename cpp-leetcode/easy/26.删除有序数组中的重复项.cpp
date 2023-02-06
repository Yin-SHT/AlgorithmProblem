/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int k = 0, N = nums.size();
        for (int i = 1; i < N; i++) {
            if (nums[k] != nums[i]) {
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
};
// @lc code=end

