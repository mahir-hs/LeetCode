/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        int x = 0;
        for (auto k : s)
        {
            if (k == '(')
            {
                st.push(x);
                x = 0;
            }
            else
            {
                x = st.top() + max(x * 2, 1);
                st.pop();
            }
        }
        return x;
    }
};
// @lc code=end
