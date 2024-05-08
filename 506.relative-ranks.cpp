/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {

        int n = score.size();
        vector<int> temp;
        temp = score;
        unordered_map<int, string> m;
        sort(temp.begin(), temp.end(), greater<int>());
        for (int i = 0; i < temp.size(); i++)
        {
            if (i < 3)
            {
                switch (i)
                {
                case 0:
                    m[temp[i]] = "Gold Medal";
                    break;
                case 1:
                    m[temp[i]] = "Silver Medal";
                    break;
                case 2:
                    m[temp[i]] = "Bronze Medal";
                    break;
                }
            }
            else
                m[temp[i]] = to_string(i + 1);
        }

        vector<string> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back(m[score[i]]);
        }
        return ans;
    }
};
// @lc code=end
