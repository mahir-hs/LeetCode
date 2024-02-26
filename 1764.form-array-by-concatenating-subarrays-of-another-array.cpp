/*
 * @lc app=leetcode id=1764 lang=cpp
 *
 * [1764] Form Array by Concatenating Subarrays of Another Array
 */

// @lc code=start
class Solution
{
public:
    long long hash[1000], h = 97, mod = 1e9 + 7, fh[1000];
    void init(vector<int> &v)
    {
        fh[0] = 1;
        for (int i = 1; i < v.size(); i++)
        {
            fh[i] = (fh[i - 1] * h) % mod;
        }

        long long val = 0;

        for (int i = 0; i < v.size(); i++)
        {
            val = (val * h) + abs(v[i]);
            val %= mod;
            hash[i] = val;
        }
    }
    long long x(int l, int r)
    {
        long long p = hash[r];

        if (l)
        {
            p = (p - fh[r - l + 1] * hash[l - 1]) % mod;
            if (p < 0)
                p += mod;
        }
        return p;
    }
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {
        init(nums);
        int last = 0;
        bool ans = false;
        for (auto k : groups)
        {
            long long val = 0;
            for (int i = 0; i < k.size(); i++)
            {
                val = (val * h) + abs(k[i]);
                val %= mod;
            }

            int idx = k.size();
            ans = false;
            for (int i = last; i < nums.size(); i++)
            {
                if (i + idx > nums.size())
                {
                    return false;
                }
                // cout << i << " " << val << " " << x(i, i + idx - 1) << " " << i + idx - 1 << endl;
                if (val == x(i, i + idx - 1))
                {

                    last = i + idx;
                    ans = true;
                    break;
                }
            }
            if (ans == false)
                return ans;
        }
        return true;
    }
};
// @lc code=end
