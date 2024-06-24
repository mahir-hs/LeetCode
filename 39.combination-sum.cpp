/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void go(int i,vector<int> &candidates, int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }

        if(i>=candidates.size() || target<0)
            return;

        temp.push_back(candidates[i]);
        go(i,candidates,target-candidates[i]);
        temp.pop_back();
        go(i+1,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        go(0,candidates,target); 
        return ans;
    }
};
// @lc code=end
