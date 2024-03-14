/*
 * @lc app=leetcode id=3075 lang=cpp
 *
 * [3075] Maximize Happiness of Selected Children
 */

// @lc code=start
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {

        sort(happiness.rbegin(), happiness.rend());

        int cnt = 0;
        long long ans = 0;
        for (auto kk : happiness)
        {
            if (k <= 0)
                break;
            k--;
            int x = kk - cnt;
            if (x <= 0)
                break;
            ans += x;
            cnt++;
        }
        return ans;
    }
};
// @lc code=end

