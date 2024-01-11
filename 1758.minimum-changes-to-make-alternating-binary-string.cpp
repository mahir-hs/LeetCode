/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
class Solution
{
public:
    int minOperations(string s)
    {
        int ans = s.size();
        int cnt = 0;
        int k = 0;
        for (int i = 0; i < s.size(); i += 2)
        {
            k++;
            if (s[i] != s[0])
            {
                cnt++;
            }
        }
        int cnt2 = 0, k2 = 0;
        for (int i = 1; i < s.size(); i += 2)
        {
            k2++;
            if (s[i] == s[0])
            {
                cnt2++;
            }
        }
        ans = min(ans, cnt + cnt2);
        cnt = k - cnt;
        cnt2 = k2 - cnt2;
        ans = min(ans, cnt + cnt2);
        return ans;
    }
};
// @lc code=end
