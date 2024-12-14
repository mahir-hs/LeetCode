/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {

        vector<pair<int, int>> v;
        for (int i = 0; i < position.size(); i++)
        {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());

        vector<float> s;
        for (int i = 0; i < v.size(); i++)
        {
            float now = (target - v[i].first) / (float)v[i].second;
            while (s.size() && s.back() <= now)
            {
                s.pop_back();
            }
            s.push_back(now);
        }
        
        return s.size();
    }
};
// @lc code=end
