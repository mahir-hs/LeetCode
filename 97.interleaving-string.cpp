/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        bool dp[n1+1][n2+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= n1; i++) dp[i][0] = (dp[i-1][0] && s1[i-1] == s3[i-1]);
        for (int i = 1; i <= n2; i++) dp[0][i] = (dp[0][i-1] && s2[i-1] == s3[i-1]);

        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);

        return dp[n1][n2];
        
    }
};
// @lc code=end

