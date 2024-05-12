/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */

// @lc code=start
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pqmn;
        priority_queue<int> pqmx;
        int n = quality.size();
        for (int i = 0; i < n; i++)
        {
            pqmn.push({(double)wage[i] / quality[i], quality[i]});
        }
        double SumQuality = 0;
        double ans = INT_MAX;
        while (!pqmn.empty())
        {
            pair<double, int> p = pqmn.top();
            SumQuality += p.second;
            pqmx.push(p.second);
            pqmn.pop();
            if (pqmx.size() > k)
            {
                SumQuality -= pqmx.top();
                pqmx.pop();
            }
            if (pqmx.size() == k)
            {
                ans = min(ans, SumQuality * p.first);
            }
        }
        return ans;
    }
};
// @lc code=end

