/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(string a, string b)
    {
        return a + b > b + a;
    }
    string largestNumber(vector<int> &nums)
    {
        vector<string> v;

        string s;

        for (int i = 0; i < nums.size(); i++)
            v.push_back(to_string(nums[i]));

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); i++)
            s += v[i];

        if (s[0] == '0')
            return "0";
        else
            return s;
    }
};
// @lc code=end
