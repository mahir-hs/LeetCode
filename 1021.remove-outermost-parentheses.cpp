/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int count = 0;
        queue<char> q;
        for (int i = 0; i < s.length(); i++)
        {
            q.push(s[i]);
            if (s[i] == '(')
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count == 0)
            {
                q.pop();
                while (!q.empty())
                {
                    ans += q.front();
                    q.pop();
                }
                ans.pop_back();
            }
        }
        return ans;
    }
};
// @lc code=end
