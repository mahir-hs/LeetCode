/*
 * @lc app=leetcode id=3226 lang=cpp
 *
 * [3226] Number of Bit Changes to Make Two Integers Equal
 */

// @lc code=start
class Solution
{
public:
    int minChanges(int n, int k)
    {
        if (n < k)
            return -1;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if ((n & (1 << i)) == 0 && (k & (1 << i)))
            {
                return -1;
            }
            else if ((n & (1 << i)) && (k & (1 << i)) == 0)
            {
                ans++;
                n = (n & ~(1 << i));
            }

            if (n < k)
                return -1;
        }

        return ans;
    }
};
// @lc code=end
