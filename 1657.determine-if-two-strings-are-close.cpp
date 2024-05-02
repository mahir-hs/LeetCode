/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {

        map<char, int> a, b;
        for (auto k : word1)
        {
            a[k]++;
        }
        for (auto k : word2)
        {
            b[k]++;
        }

        map<int, set<char>> x, y;
        vector<int> v1, v2;
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (a[i] != 0)
            {
                x[a[i]].insert(i);
            }
            if (b[i] != 0)
            {
                y[b[i]].insert(i);
            }
        }

        for (char i = 'a'; i <= 'z'; i++)
        {
            if (a[i] == 0 && b[i] == 0)
                continue;

            if (a[i] == 0 || b[i] == 0)
            {
                return false;
            }
            if (b[i])
            {
                if (a[i] == b[i])
                {
                    x[a[i]].erase(i);
                    a[i] = 0;
                    b[i] = 0;
                    continue;
                }
                else
                {
                    if (x[b[i]].empty())
                    {
                        return false;
                    }


                    char c = *x[b[i]].begin();
                    x[b[i]].erase(c);
                    x[a[i]].erase(i);
                    a[c] = a[i];
                    x[a[i]].insert(c);
                }
            }
        }
        return true;
    }
};
// @lc code=end
