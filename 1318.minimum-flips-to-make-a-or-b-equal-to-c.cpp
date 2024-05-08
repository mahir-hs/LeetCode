/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution
{
public:
    bool isOn(long long n, long long pos)
    {
        return (bool)(n & ((long long)1 << pos));
    }
    int minFlips(int a, int b, int c)
    {

        long long x = (a | b);
        int ans = 0;
        for (long long i = 30; i >= 0; i--)
        {
            bool val = isOn(x, i);
            bool val2 = isOn(c, i);
            if (val != val2)
            {
                if (val2 == false)
                {
                    if (isOn(a, i) != val2)
                        ans++;
                    if (isOn(b, i) != val2)
                        ans++;
                }
                else
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
