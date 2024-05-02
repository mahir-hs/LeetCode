/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        if(s.size() ==0)
            return true;
        int x = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s[x] == t[i])
            {
                x++;
                if(x == s.size())
                    return true;
            }
        }

        return false;
    }
};
// @lc code=end
