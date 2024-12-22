/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution
{
public:
    int numTilings(int n)
    {

        long mod = 1e9 + 7;
        vector<long long> dp(n + 3, 0L);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;
        for (int i = 3; i < n; i++)
        {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % mod;
        }
        return dp[n - 1];
    }
};
// @lc code=end
