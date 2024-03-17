/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.rbegin(), potions.rend());

        vector<int> ans;
        int sz = potions.size();
        for(auto k:spells)
        {
            int l = 0, r = potions.size()-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                long long x = (long long)potions[mid]*k;
                if(x >= success)
                    l = mid+1;
                else
                    r = mid-1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};
// @lc code=end

