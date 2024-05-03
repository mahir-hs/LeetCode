/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution
{
public:
    string predictPartyVictory(string senate)
    {

        queue<int> q1, q2;
        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
                q1.push(i);
            else
                q2.push(i);
        }
        while (!q1.empty() && !q2.empty())
        {
            int r = q1.front();
            int d = q2.front();
            q1.pop();
            q2.pop();
            if (r < d)
            {
                q1.push(r + senate.size());
            }
            else
            {
                q2.push(d + senate.size());
            }
        }

        if (q1.size() > q2.size())
            return "Radiant";

        return "Dire";
    }
};
// @lc code=end
