/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int kom = prices[0], beshi = prices[0];
        for (auto k : prices)
        {
             if(k<=beshi)
             {
                 ans += beshi - kom;
                 kom = k;
                 beshi = k;
             }
             else
             {
                 beshi = k;
             }
        }
        ans += beshi - kom;
        return ans;
    }
};
// @lc code=end
