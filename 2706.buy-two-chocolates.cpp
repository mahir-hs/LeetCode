/*
 * @lc app=leetcode id=2706 lang=cpp
 *
 * [2706] Buy Two Chocolates
 */

// @lc code=start
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

        sort(prices.begin(), prices.end());
        int sum = prices[0] + prices[1];
        sum = money-sum;
        if(sum>=0)
            return sum;
        return money;
    }
};
// @lc code=end

