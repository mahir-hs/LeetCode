/*
 * @lc app=leetcode id=1913 lang=cpp
 *
 * [1913] Maximum Product Difference Between Two Pairs
 */

// @lc code=start
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        int x = ((nums.back()) * (nums[nums.size()-2])) - ((nums[0]) * (nums[1]));
        return x;
    }
};
// @lc code=end
