/*
 * @lc app=leetcode id=2957 lang=cpp
 *
 * [2957] Remove Adjacent Almost-Equal Characters
 */

// @lc code=start
class Solution
{
public:
    int removeAlmostEqualCharacters(string word)
    {

        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (word[i] == word[i + 1] || word[i] + 1 == word[i + 1] || word[i] == word[i + 1] + 1)
            {
                ++ans;
                word[i + 1] = '@';
            }
        }
        return ans;
    }
};
// @lc code=end
