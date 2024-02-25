/*
 * @lc app=leetcode id=1392 lang=cpp
 *
 * [1392] Longest Happy Prefix
 */

// @lc code=start
class Solution
{
public:
    long long hash[(int)1e5+100], com[(int)1e5+100], mod = 1e9 + 7, val = 97;

    void init(string &s)
    {
        com[0] = 1;
        for (int i = 1; i < s.size()+1; i++)
        {
            com[i] = (com[i - 1] * val) % mod;
        }
        long long h = 0;
        for (int i = 0; i < s.size(); i++)
        {
            h = (h * val) + s[i];
            h %= mod;
            hash[i] = h;
        }
    }

    long long fh(int l, int r)
    {
        int h = hash[r];
        if (l)
        {
            h = (h - hash[l - 1] * com[r - l + 1]) % mod;
            if (h < 0)
                h += mod;
        }
        return h;
    }

    string longestPrefix(string s)
    {
        init(s);
        string ans;
        int idx = -1;
        int j = s.size() - 1;
        for (int i = 0; i < s.size() - 1; i++)
        {
            // cout << fh(0, i) << " " << fh(j - i, j) << endl;
            // cout << i << " " << j - i << " " << j << endl;
            if (fh(0, i) == fh(j - i, j))
            {
                idx = i;
            }
        }
        if (idx >= 0)
            for (int i = 0; i <= idx; i++)
            {
                ans += s[i];
            }
        return ans;
    }
};
// @lc code=end
