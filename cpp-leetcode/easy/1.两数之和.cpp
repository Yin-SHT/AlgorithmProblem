/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int N = nums.size();
        for ( int i = 0; i < N; i++ ) {
            for ( int j = i + 1; j < N; j++ ) {
                if (nums[i] + nums[j] == target)
                    return std::vector<int>{ i, j };
            }
        }
        return std::vector<int>{};
    }
};
// @lc code=end

