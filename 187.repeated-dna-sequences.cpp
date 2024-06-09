/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution
{
public:
    long long mod = 1e9 + 7, mod2 = 2117566807, h = 131, h2 = 1572872831;
    long long val = 0, val2 = 0;
    vector<long long> arr, arr2, cal, cal2;

    void init(string &s)
    {

        arr.resize(s.size() + 1);
        arr2.resize(s.size() + 1);
        cal.resize(s.size() + 1);
        cal2.resize(s.size() + 1);
        for (int i = 0; i < s.size(); i++)
        {
            val = (val * h) + s[i];
            val2 = (val2 * h2) + s[i];
            val %= mod;
            val2 %= mod2;
            arr[i] = val;
            arr2[i] = val2;
        }
        cal[0] = 1;
        cal2[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            cal[i] = (cal[i - 1] * h) % mod;
            cal2[i] = (cal2[i - 1] * h2) % mod2;
        }
    }
    long long fh(int l, int r)
    {

        long long now = arr[r];

        if (l)
        {
            now = (now - cal[r - l + 1] * arr[l - 1]) % mod;
            if (now < 0)
                now += mod;
        }

        return now;
    }

    long long fh2(int l, int r)
    {
        long long now = arr2[r];
        if (l)
        {
            now = (now - cal2[r - l + 1] * arr2[l - 1]) % mod2;
            if (now < 0)
                now += mod2;
        }
        return now;
    }
    vector<string> findRepeatedDnaSequences(string s)
    {

        unordered_map<long long, int> mp, mp2;
        vector<string> res;
        init(s);
        for (int i = 9; i < s.size(); i++)
        {
            if (mp[fh(i - 9, i)] == 1 and mp2[fh2(i - 9, i)] == 1)
                res.push_back(s.substr(i - 9, 10));
            mp[fh(i - 9, i)]++;
            mp2[fh2(i - 9, i)]++;
        }
        return res;
    }
};
// @lc code=end
