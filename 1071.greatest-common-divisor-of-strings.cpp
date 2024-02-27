/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution
{
public:
    long long hash1[1010], hash2[1010], h = 97, mod = 1e9 + 7, p[1010];
    void init(string &a, string &b)
    {
        p[0] = 1;

        for (int i = 1; i < b.size(); i++)
            p[i] = (p[i - 1] * h) % mod;

        long long val = 0;
        for (int i = 0; i < a.size(); i++)
        {
            val = (val * h) + a[i];
            val %= mod;
            hash1[i] = val;
        }
        val = 0;
        for (int i = 0; i < b.size(); i++)
        {
            val = (val * h) + b[i];
            val %= mod;
            hash2[i] = val;
        }
    }
    long long fh(int l, int r, long long arr[])
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
    string gcdOfStrings(string str1, string str2)
    {

        if (str1.size() > str2.size())
            swap(str1, str2);

        init(str1, str2);

        vector<int> v;
        int x = __gcd(str1.size(), str2.size());
        v.push_back(x);
        int a = str1.size(), b = str2.size();
        for (int i = 1; i < x; i++)
        {
            if (a % i == 0 and b % i == 0)
                v.push_back(i);
        }
        sort(v.rbegin(), v.rend());

        string ans;
        for (auto k : v)
        {
            string temp;
            for (int i = 0; i < k; i++)
            {
                temp += str1[i];
            }
            int g = fh(0, k - 1, hash1);
            bool ok = true;
            for (int i = 0; i < a; i += k)
            {
                if (g == fh(i, i + k - 1, hash1))
                    continue;
                ok = false;
                break;
            }
            if (ok == false)
                break;
            for (int i = 0; i < b; i += k)
            {
                if (g == fh(i, i + k - 1, hash2))
                    continue;
                ok = false;
                break;
            }
            if (ok)
            {
                ans = temp;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
