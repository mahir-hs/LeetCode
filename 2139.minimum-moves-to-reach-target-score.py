#
# @lc app=leetcode id=2139 lang=python
#
# [2139] Minimum Moves to Reach Target Score
#

# @lc code=start
class Solution(object):
    def minMoves(self, target, maxDoubles):
        """
        :type target: int
        :type maxDoubles: int
        :rtype: int
        """
        
        ans = 0
       
        while target > 1 and maxDoubles > 0:
            if target % 2 == 1:
                ans += 1
                target -= 1
            else:
                ans += 1
                target = target / 2
                maxDoubles -= 1
        return ans + target - 1
        
# @lc code=end

