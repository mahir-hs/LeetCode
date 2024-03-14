/*
 * @lc app=leetcode id=3076 lang=cpp
 *
 * [3076] Shortest Uncommon Substring in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<string> shortestSubstrings(vector<string> &arr)
    {

        vector<string> ans;
        unordered_map<string, int> mp;
        vector<vector<string>> v;
        auto cmp = [](const string &a, const string &b)
        {
            if (a.size() != b.size())
                return a.size() < b.size();
            return a < b;
        };
        for (auto k : arr)
        {
            string now = k;
            vector<string> temp;
            unordered_map<string, int> mm;
            for (int i = 0; i < now.size(); i++)
            {
                for (int j = i; j < now.size(); j++)
                {
                    string x = now.substr(i, j - i + 1);
                    temp.push_back(x);
                    mm[x]++;
                    if (mm[x] == 1)
                        mp[x]++;
                    // cout<<i<<" "<<j<<" "<<j-i+1<<" "<<x<<endl;
                }
            }
            sort(temp.begin(), temp.end(), cmp);
            v.push_back(temp);
        }

        for (auto k : v)
        {
            bool ok = false;
            for (auto kk : k)
            {
                if (mp[kk] == 1)
                {
                    ok = true;
                    ans.push_back(kk);
                    break;
                }
            }
            if (!ok)
                ans.push_back("");
        }
        return ans;
    }
};
// @lc code=end

