/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution
{
public:
    string removeStars(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
                st.pop();
            else
                st.push(s[i]);
        }

        s.clear();

        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end
