/*
 * @lc app=leetcode id=1668 lang=cpp
 *
 * [1668] Maximum Repeating Substring
 */

// @lc code=start
class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        string s = word;
        int ans = 0;
        if (word.size() > sequence.size())
            return 0;
        while (true)
        {
            bool ok = false;
            for (int i = 0; i <= sequence.size() - s.size(); i++)
            {
                string k;
                for (int j = i; j < i + s.size(); j++)
                {
                    k += sequence[j];
                }
                if (k == s)
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
            {
                s += word;
                ans++;
                if (s.size() > sequence.size())
                    break;
            }
            else
                break;
        }
        return ans;
    }
};
// @lc code=end
