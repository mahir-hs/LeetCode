/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {

        int ans = 0, left = 0, right = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                right++;
            }
            else
            {
                left = right;
                right = 0;
            }
            ans = max(ans, left + right);
        }

        if (ans == nums.size())
            ans--;
        return ans;
    }
};
// @lc code=end
