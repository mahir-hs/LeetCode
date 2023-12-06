/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size();i++)
        {
            if(nums[i]==target)
                return i;
        }
        return -1;
    }
};
// @lc code=end

