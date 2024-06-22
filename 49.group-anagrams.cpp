/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, vector<string>> mp;
        for (auto k : strs)
        {
            string s = k;
            sort(s.begin(), s.end());
            mp[s].push_back(k);
        }

        vector<vector<string>> ans;

        for (auto k : mp)
        {
            sort(k.second.begin(), k.second.end());
            ans.push_back(k.second);
        }
        return ans;
    }
};
// @lc code=end
