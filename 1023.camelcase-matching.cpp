/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 */

// @lc code=start
class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> ans;

        for (auto &k : queries)
        {
            string s, ss, c;
            int i = 0, j = 0;

            for (int p = 0; p < k.size(); p++)
            {
                if (k[p] >= 'A' and k[p] <= 'Z')
                    ss += k[p];
            }
            while (i < pattern.size() and j < k.size())
            {
                if (pattern[i] == k[j])
                {
                    if (pattern[i] >= 'A' and pattern[i] <= 'Z')
                        c += pattern[i];
                    s += k[j];
                    i++;
                }
                j++;
            }
            if (s == pattern and ss == c)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
// @lc code=end
