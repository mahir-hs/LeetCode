/*
 * @lc app=leetcode id=2202 lang=cpp
 *
 * [2202] Maximize the Topmost Element After K Moves
 */

// @lc code=start
class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {
        if (k == 0)
            return nums[0];
        if (nums.size() == 1 && k % 2 == 0)
            return nums[0];
        if (nums.size() == 1 && k % 2 == 1)
            return -1;

        int pq = 0;
        for (int i = 0; i < min((int)nums.size(), k - 1); i++)
        {
            pq = max(pq, nums[i]);
        }
        int ans = 0;
        if (nums.size() > k)
            ans = nums[k];
        return max(pq, ans);
    }
};
// @lc code=end
