/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> v;
        unordered_map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}, {'(', ')'}, {'[', ']'}, {'{', '}'}};
        for (auto k : s)
        {
            if (k == '(' || k == '{' || k == '[')
            {
                v.push_back(k);
            }
            else
            {
                if (v.empty())
                    return false;
                    
                if (m[v.back()] == k)
                {
                    v.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }
        if (v.size())
            return false;
        return true;
    }
};
// @lc code=end
