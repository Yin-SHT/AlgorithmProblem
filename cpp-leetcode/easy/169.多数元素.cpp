/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int N = nums.size(), flag = 0, count = 0;
        for (int i = 0; i < N; i++) {
            if (count == 0) {
                flag = nums[i];
                count++;
                continue;
            }
            if (nums[i] != flag) {
                count--;
            } else if (nums[i] == flag) {
                count++;
            }
        }
        return flag;
    }
};
// @lc code=end

