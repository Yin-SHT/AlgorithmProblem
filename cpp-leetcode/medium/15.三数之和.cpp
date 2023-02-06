/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>

void skip(std::vector<int > &nums, int &idx, int dir) {
    int flag = nums[idx];
    if (dir == 1) {
        while (idx < nums.size() && nums[idx] == flag) {
            idx++;
        }
    } else if (dir == 0) {
        while (idx > -1 && nums[idx] == flag) {
            idx--;
        }
    } 
}

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> resGruop;
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int k = 0, i = 1, j = N - 1; k < N && nums[k] <= 0; k++, i = k + 1, j = N - 1) {
            if (k < N && k > 0 && nums[k] == nums[k - 1]) {
                skip(nums, k, 1);
                i = k + 1;
                j = N - 1;
            }
            while (k < N && i < N && j > -1 && i < j) {
                int tempSum = nums[k] + nums[i] + nums[j];
                if (tempSum == 0) {
                    resGruop.emplace_back(std::vector<int>{nums[k], nums[i], nums[j]});
                    skip(nums, i, 1);
                    skip(nums, j, 0);
                } else if (tempSum < 0) {
                    skip(nums, i, 1);
                } else if (tempSum > 0) {
                    skip(nums, j, 0);
                }
            }
        }
        return resGruop;
    }
};
// @lc code=end

