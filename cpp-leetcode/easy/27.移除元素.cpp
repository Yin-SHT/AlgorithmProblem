/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int repNum = 0, N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] != val) {
                nums[i - repNum] = nums[i];
            } else {
                repNum++;
            }
         }
        return N - repNum;
    }
};
// @lc code=end

