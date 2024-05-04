/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
public:
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> ans;

    void go(string digits, int index, string s)
    {

        if (index == digits.size())
        {
            ans.push_back(s);
            return;
        }

        string str = mp[digits[index]];

        for (int i = 0; i < str.size(); i++)
        {
            go(digits, index + 1, s + str[i]);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return ans;
        go(digits, 0, "");
        return ans;
    }
};
// @lc code=end
