/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, bool> mp;

    bool dfs(string a, string b)
    {

        if (a == b)
            return true;

        if (a.size() <= 1)
            return false;
        if (mp.find(a + " " + b) != mp.end())
            return mp[a + " " + b];

        bool ans = false;
        for (int i = 1; i < a.size(); i++)
        {
            if (dfs(a.substr(0, i), b.substr(b.size() - i)) and dfs(a.substr(i), b.substr(0, b.size() - i)))
            {
                ans = true;
                break;
            }
            if (dfs(a.substr(0, i), b.substr(0, i)) and dfs(a.substr(i), b.substr(i)))
            {
                ans = true;
                break;
            }
        }
         return mp[a + " " + b] = ans;
    }
    bool isScramble(string s1, string s2)
    {

        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;

        return dfs(s1, s2);
    }
};
// @lc code=end
