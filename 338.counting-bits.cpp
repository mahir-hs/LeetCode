/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int n)
    {

        vector<int> ans;
        ans.emplace_back(0);
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 17; j >= 0; j--)
            {
                if (i & (1<<j))
                    cnt++;
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};
// @lc code=end
