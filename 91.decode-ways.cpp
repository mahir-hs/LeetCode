/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int dp[(int)2e5 + 10];
    int go(int idx, string &s)
    {
        if (idx == s.size())
            return 1;

        if (s[idx] == '0')
            return 0;

        if (~dp[idx])
            return dp[idx];
        int ans = go(idx + 1, s);

        if (idx + 1 < s.size() and (s[idx] == '1' or (s[idx] == '2' and s[idx + 1] <= '6')))
            ans += go(idx + 2, s);
        dp[idx] = ans;
        return ans;
    }
    int numDecodings(string s)
    {
        memset(dp, -1, sizeof(dp));
        return go(0, s);
    }
};
// @lc code=end
