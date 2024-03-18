/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution
{
public:
    bool dfs(string start, string end, unordered_map<string, vector<pair<string, double>>> &m, unordered_set<string> &visit, double &ans)
    {
        if (visit.count(start))
            return false;
        if(!m.count(start) or !m.count(end))
            return false;
        if (start == end)
            return true;
        visit.insert(start);
        for (auto [k, v] : m[start])
        {
            double updated_ans = ans;
            ans*=v;
            if (dfs(k, end, m, visit,ans))
                return true;
            ans = updated_ans;
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        unordered_map<string, vector<pair<string, double>>> m;
        for (int i = 0; i < equations.size(); i++)
        {
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1.0 / (1.0*values[i])});
        }

          vector<double> res;
        for (int i = 0; i < queries.size(); i++)
        {
            double ans = 1;
            unordered_set<string> visit;
            if (dfs(queries[i][0], queries[i][1], m, visit, ans))
                res.push_back(ans);
            else
                res.push_back(-1);
        }
        return res;
    }
};
// @lc code=end
