/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int n = nums.size();
        int ans = *min_element(nums.begin(), nums.end());
        int cnt = 0;
        for (auto k : nums)
        {
            if (k < 0)
                cnt++;
        }
        if (cnt == n)
        {
            return *max_element(nums.begin(), nums.end());
        }

        int now = 0;
        for (size_t i = 0; i < n; i++)
        {
            now += nums[i];
            if (now < 0)
            {
                now = 0;
            }
            else
            {
                ans = max(ans, now);
            }
        }
        ans = max(ans, now);
        return ans;
    }
};
// @lc code=end
