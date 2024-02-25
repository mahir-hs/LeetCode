/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution
{
public:
    int minPartitions(string n)
    {

        int ans = 0;
        int last = 0, i;
        while (true)
        {
            bool ok = false;
            for (int i = 0; i < n.size(); i++)
            {
                if (n[i] - '0' >= 1)
                {
                    ok = true;
                    n[i]--;
                    continue;
                }
                n[i]--;
            }
            if (ok == false)
                break;
            ans++;
        }
        return ans;
    }
};
// @lc code=end
