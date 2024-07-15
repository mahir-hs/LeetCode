/*
 * @lc app=leetcode id=202 lang=csharp
 *
 * [202] Happy Number
 */

// @lc code=start
public class Solution
{
    public bool IsHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }

        HashSet<int> s = new HashSet<int>();
        s.Add(n);

        while (n != 1)
        {
            int sum = 0;
            while (n > 0)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }

            if (sum == 1)
            {
                return true;
            }
            
            if (s.Contains(sum))
            {
                return false;
            }

            s.Add(sum);

            n = sum;
        }

        return false;

    }
}
// @lc code=end

