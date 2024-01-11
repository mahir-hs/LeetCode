/*
 * @lc app=leetcode id=2496 lang=cpp
 *
 * [2496] Maximum Value of a String in an Array
 */

// @lc code=start
class Solution
{
public:
    int maximumValue(vector<string> &strs)
    {

        int ans = 0;

        for (auto k : strs)
        {
            bool ok = false;
            for (int i = 0; i < k.size(); i++)
            {
                if (k[i] >= 'a' and k[i] <= 'z')
                {
                    ok = true;
                    break;
                }
            }
            int x = 0;
            if (ok == false)
                x = stoi(k);
            else
            {
                x = k.size();
            }
            ans = max(ans, x);
        }
        return ans;
    }
};
// @lc code=end
