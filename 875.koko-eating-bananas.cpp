/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h)
    {
        int time = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            time += (piles[i] + mid - 1) / mid;
            if(time > h)
                return false;
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(canEat(piles, mid, h))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
// @lc code=end

