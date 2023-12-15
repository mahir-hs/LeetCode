/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {

        unordered_map<string, int> b;
       

        for (int i = 0; i < paths.size(); i++)
        {
            b[paths[i][1]]++;
            b[paths[i][0]]++;
            
        }
        string ans;
        for (int i = 0; i < paths.size();i++)
        {
            if (b[paths[i][1]] == 1)
            {
                ans = paths[i][1];
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
