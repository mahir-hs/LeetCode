/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int ans = 0;
        for (auto it : nums)
            m[it]++;

        for (auto it : nums)
        {
            int x = k - it;
            if (m[it])
            {
                m[it]--;
                if (m[x])
                {
                    ans++;
                    m[x]--;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
