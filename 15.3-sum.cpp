/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        map<int, vector<int>> m;
        set<vector<int>> s;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int x = n - 1;
            int j = i + 1;
            while (j < x)
            {
                int now = nums[i] + nums[j] + nums[x];
                if(now==0)
                {
                    s.insert({nums[i], nums[j], nums[x]});
                    j++;
                    x--;
                }
                else if(now>0)
                {
                    x--;
                }
                else{
                    j++;
                }
            }
        }
        for (auto k : s)
            ans.push_back(k);
        return ans;
    }

  
};
// @lc code=end
