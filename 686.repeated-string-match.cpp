/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// @lc code=start
class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {

        int ans = 0;
        string x;
        while (x.size() < b.size())
        {
            ans++;
            x += a;
        }

        if (x.find(b) != string::npos)
        {
            return ans;
        }
        x += a;
        ans++;
        if (x.find(b) != string::npos)
        {
            return ans;
        }
        return -1;
    }
};
// @lc code=end
