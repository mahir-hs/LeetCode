/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        map<int, int> m = {{'a', 1}, {'e', 2}, {'i', 3}, {'o', 4}, {'u', 5}};
        int ans = 0;
        int x = 0;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i >= k)
            {
                if (m[s[i - k]])
                    cnt--;
            }
            if (m[s[i]])
                cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end
