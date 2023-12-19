/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int ans = 0;

        while (i < j)
        {
            int now = min(height[i], height[j]);
            ans = max(ans, now * (j - i));
            while (height[i] <= now and i < j)
                i++;
            while (height[j] <= now and i < j)
                j--;
        }
        return ans;
    }
};
// @lc code=end
