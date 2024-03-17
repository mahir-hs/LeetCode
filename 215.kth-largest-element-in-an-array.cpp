/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>p;

        for(int i=0;i<nums.size();i++)
        {
            p.push(nums[i]);
        }
        
        while (k>1)
        {
            /* code */
            k--;
            p.pop();
        }
        return p.top();
        }
};
// @lc code=end

