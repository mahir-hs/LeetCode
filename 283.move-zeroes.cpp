/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int i = 0, j = 0;
        bool ok = false;

        while(i<n)
        {
            if(nums[i]==0)
            {
                j = i;
                while(j<n)
                {
                    if(nums[j]!=0)
                    {
                        swap(nums[i], nums[j]);
                        ok = true;
                        break;
                    }
                    j++;
                }
                if(ok==false)
                {
                    break;
                }
            }
            i++;
        }
    }
};
// @lc code=end

