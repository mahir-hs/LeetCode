/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution
{
public:
    long long mod = 1e9 + 7, h = 131;
    vector<long long> p, arr;
    void init(string &s)
    {
        p.resize(s.size() + 1);
        arr.resize(s.size() + 1);
        long long now = 0;
        for (int i = 0; i < s.size(); i++)
        {
            now = (now * h) + s[i];
            now %= mod;
            arr[i] = now;
        }

        p[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            p[i] = (p[i - 1] * h) % mod;
        }
    }

    long long fh(int l, int r)
    {
        long long now = arr[r];
        if (l)
        {
            now = (now - p[r - l + 1] * arr[l - 1]) % mod;
            if (now < 0)
                now += mod;
        }
        return now;
    }
    bool hasAllCodes(string s, int k)
    {
        init(s);
        int val = (1 << k);
        int cnt = 0;
        unordered_map<long long, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (i - k + 1 >= 0)
            {
                mp[fh(i - k + 1, i)]++;
                if (mp[fh(i - k + 1, i)] == 1)
                    cnt++;
            }
        }
        if (cnt == val)
            return true;
        else
            return false;
    }
};
// @lc code=end
