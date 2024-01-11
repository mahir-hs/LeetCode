/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution
{
public:
    int maxScore(string s)
    {

        int zero = 0, one = 0;

        for (auto k : s)
        {
            if (k == '1')
                one++;
        }
        int ans = 0;
        for (int i = 0; i < s.size()-1; i++)
        {
            if(s[i]=='1')
            {
                one--;
                ans = max(ans, one + zero);
            }
            else
            {
                zero++;
                ans = max(ans, one + zero);
            }
        }
        return ans;
    }
};
// @lc code=end
