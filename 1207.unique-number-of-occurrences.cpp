/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m, count;
        set<int> s;
        for (auto k : arr)
        {
            s.insert(k);
            count[k]++;
        }

        for (auto k : s)
        {
            if (m[count[k]])
                return false;
            m[count[k]] = 1;
        }
        return true;
    }
};
// @lc code=end
