/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution
{
public:
    long long h = 97, mod = 1e9 + 7, hash[1010], rhash[1010], pwr[1010];
    void init(string &s)
    {
        pwr[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            pwr[i] = pwr[i - 1] * h % mod;
        }

        long long val = 0;
        for (int i = 0; i < s.size(); i++)
        {
            val = (val * h) + s[i];
            val %= mod;
            hash[i] = val;
        }

        val = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            val = (val * h) + s[i];
            val %= mod;
            rhash[i] = val;
        }
    }

    long long fh(int l, int r)
    {
        long long now = hash[r];
        if (l)
        {
            now = (now - pwr[r - l + 1] * hash[l - 1]) % mod;
            if (now < 0)
                now += mod;
        }
        return now;
    }
    long long rh(int l, int r,int n)
    {
        long long now = rhash[l];
        if (r+1<n)
        {
            now = (now - pwr[r - l + 1] * rhash[r+1]) % mod;
            if (now < 0)
                now += mod;
        }
        return now;
    }
    int countSubstrings(string s)
    {
        init(s);

        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (fh(i, j) == rh(i, j,s.size()))
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
