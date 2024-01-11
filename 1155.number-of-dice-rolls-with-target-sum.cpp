/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {

        int mod = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                for (int x = 1; x <= k; x++)
                {
                    if (x <= j)
                    {
                        dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j - x] % mod)) % mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};
// @lc code=end
