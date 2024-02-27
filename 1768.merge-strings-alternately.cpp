/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {

        string ans;
        bool ok = true;
        reverse(word1.begin(), word1.end());
        reverse(word2.begin(), word2.end());
        while (word1.empty() == false or word2.empty() == false)
        {
            if (word1.empty())
            {
                ans += word2.back();
                word2.pop_back();
                continue;
            }
            if (word2.empty())
            {
                ans += word1.back();
                word1.pop_back();
                continue;
            }
            if (ok)
            {
                ans += word1.back();
                word1.pop_back();
                ok = false;
            }
            else
            {
                ans += word2.back();
                word2.pop_back();
                ok = true;
            }
        }
        return ans;
    }
};
// @lc code=end
