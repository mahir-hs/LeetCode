/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner
{
public:
    vector<pair<int, int>> v;
    StockSpanner()
    {
    }

    int next(int price)
    {

        int cnt = 1;

        while (!v.empty() && v.back().first <= price)
        {
            cnt += v.back().second;
            v.pop_back();
        }

        v.push_back({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
