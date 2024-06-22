/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]++;
        }
        int i = 0, j = 0;
        int count = mp.size();
        int start = 0, end = INT_MAX;
        while (j < s.size())
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp2[s[j]]++;
                if (mp2[s[j]] == mp[s[j]])
                    count--;
            }
            while (count == 0)
            {
                if (end - start > j - i)    
                {
                    start = i;
                    end = j;
                }
                if (mp.find(s[i]) != mp.end())
                {
                    mp2[s[i]]--;
                    if (mp2[s[i]] < mp[s[i]])
                        count++;
                }
                i++;
            }
            j++;
        }
        return end - start == INT_MAX ? "" : s.substr(start, end - start + 1);
    }
};
// @lc code=end
