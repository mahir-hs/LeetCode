/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    vector<string> st;
    int x;
    void go(int i, int j, string s)
    {
        if (s.size() == x * 2)
        {
            st.push_back(s);
        }
        if (i < x)
        {
            go(i + 1, j, s + '(');
        }
        if (j < i)
        {
            go(i, j + 1, s + ')');
        }
    }
    vector<string> generateParenthesis(int n)
    {
        x = n;
        go(0, 0, "");
        return st;
    }
};
// @lc code=end
