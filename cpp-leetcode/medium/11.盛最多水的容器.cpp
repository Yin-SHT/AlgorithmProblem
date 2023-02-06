/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxA = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int tempA = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
            maxA = maxA < tempA ? tempA : maxA;
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxA;
    }
};
// @lc code=end

