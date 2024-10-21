/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution
{
public:
    int kmp(string text)
    {
        vector<int> lps(text.length(), 0);

        int i = 1, j = 0;
        while (i < (int)text.length())
        {
            if (text[i] == text[j])
            {
                lps[i] = j + 1;
                i++, j++;
            }
            else
            {
                if (j)
                {
                    j = lps[j - 1];
                }
                else
                    i++;
            }
        }

        return lps.back();
    }
    string shortestPalindrome(string s)
    {
        string x = s;
        reverse(x.begin(), x.end());
        string T = s + "#" + x;
        int cnt = kmp(T);

        return x.substr(0, s.length() - cnt) + s;
    }
};
// @lc code=end
