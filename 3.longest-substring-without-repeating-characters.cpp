/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        unordered_map<char, int> count, arr;
        int ans = 0, start = 0, l = 0;

        while (l < s.size())
        {
            if (count[s[l]])
            {
                for (int i = start; i < arr[s[l]]; i++)
                {
                    count[s[i]] = 0;
                    arr[s[i]] = 0;
                }
                start = arr[s[l]] + 1;
                ans = max(ans, l - start);
                arr[s[l]] = l;
                count[s[l]] = 1;
            }
            else
            {
                count[s[l]]++;
                arr[s[l]] = l;
                ans = max(ans, l - start + 1);
            }

            ++l;
        }
        return ans;
    }
};
// @lc code=end
