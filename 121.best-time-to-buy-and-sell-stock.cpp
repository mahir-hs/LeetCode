/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int Tree[4 * 100000];
    vector<int> v;
    void init(int node, int l, int r)
    {
        if (l == r)
        {
            Tree[node] = v[l];
            return;
        }

        int mid = (l + r) >> 1;
        int left = node << 1;
        int right = (node << 1) | 1;
        init(left, l, mid);
        init(right, mid + 1, r);
        Tree[node] = max(Tree[left], Tree[right]);
    }
    int query(int node, int l, int r, int x, int y)
    {
        if (l > y || r < x)
            return 0;

        if (l >= x and r <= y)
        {
            return Tree[node];
        }
        int mid = (l + r) >> 1;
        int left = node << 1;
        int right = (node << 1) | 1;
        return max(query(left, l, mid, x, y), query(right, mid + 1, r, x, y));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        v.resize(n + 10);
        for (int i = 0; i < prices.size(); i++)
        {
            v[i + 1] = prices[i];
        }

        init(1, 1, n);

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int now = query(1, 1, n, i + 1, n);
            ans = max(ans, now - prices[i]);
        }

        return ans;
    }
};
// @lc code=end

