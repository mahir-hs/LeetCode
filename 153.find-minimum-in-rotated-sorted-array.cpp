/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        return nums[0];
    }
};
// @lc code=end
