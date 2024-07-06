/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 */

// @lc code=start
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        if(time==n)
        {
            return n-1;
        }

        if (time > n)
        {
            int div = time / (n - 1);
            int rem = time % (n - 1);

            if (div % 2 == 0)
            {
                return rem + 1;
            }
            else
            {
                return n - rem;
            }
        }
        else
        {
            return time + 1;
        }

    }
};
// @lc code=end
