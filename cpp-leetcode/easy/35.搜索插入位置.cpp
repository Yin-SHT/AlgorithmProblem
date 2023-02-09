/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while ( i < j ) {
            int mid = ( i + j ) / 2;
            if ( nums[mid] == target ) {
                return mid;
            } else if ( nums[mid] < target ) {
                i = mid + 1;
            } else if ( nums[mid] > target ) {
                j = mid - 1;
            }
        }
        if ( nums[i] >= target ) {
            return i;
        } else if ( nums[i] < target ) {
            return i + 1;
        }
        return -1;
    }
};
// @lc code=end

