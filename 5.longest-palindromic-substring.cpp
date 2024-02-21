/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

typedef long long int ll;

class Solution
{
public:
    ll mod = 1e9 + 7, prime = 97;
    ll fhash[1100], bhash[1100], powerCal[1100];
    void init(string &s)
    {
        powerCal[0] = 1;
        for (int i = 1; i < 1100; i++)
        {
            powerCal[i] = (powerCal[i - 1] * prime) % mod;
        }

        ll temp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            temp = (temp * prime) + s[i];
            temp %= mod;
            fhash[i] = temp;
        }
        temp = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            temp = (temp * prime) + s[i];
            temp %= mod;
            bhash[i] = temp;
        }
    }
    ll frontHash(int l, int r)
    {
        ll temp = fhash[r];
        if (l)
        {
            temp = (temp - powerCal[r - l + 1] * fhash[l - 1]) % mod;
            if (temp < 0)
                temp += mod;
        }
        return temp;
    }
    ll backHash(int l, int r, int n)
    {
        ll temp = bhash[l];
        if (r + 1 < n)
        {
            temp = (temp - powerCal[r - l + 1] * bhash[r + 1]) % mod;
            if (temp < 0)
                temp += mod;
        }
        return temp;
    }

    pair<int, int> p;
    int ans = 0;
    bool go(int range, string &s)
    {
        for (int i = 0; i + range < s.size(); i++)
        {
            if (frontHash(i, i + range) == backHash(i, i + range, s.size()))
            {
                if (range > ans)
                {
                    ans = range;
                    p = {i, i + range};
                    return true;
                }
            }
        }
        return false;
    }
    string longestPalindrome(string s)
    {
        init(s);

        ll l = 0, r = 1e5;

        while (l <= r)
        {
            ll mid = (l + r) / 2;

            if (go(mid, s))
            {
                l = mid + 1;
            }
            else if (go(mid + 1, s))
            {
                l = mid + 2;
            }
            else
            {
                r = mid - 1;
            }
        }

        string x;
        for (int i = p.first; i <= p.second; i++)
            x += s[i];
        return x;
    }
};
// @lc code=end
