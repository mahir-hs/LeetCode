/*
 * @lc app=leetcode id=2211 lang=cpp
 *
 * [2211] Count Collisions on a Road
 */

// @lc code=start
class Solution
{
public:
    int countCollisions(string directions)
    {
        int ans = 0;
        int isLeftColide = 0;
        int rightCount = 0;
        for (int i = 0; i < directions.size(); i++)
        {
            if (directions[i] == 'R' && directions[i + 1] == 'L')
            {
                isLeftColide = 1;
                ans += rightCount;
                ans += 2;
                rightCount = 0;
                i++;
            }
            else if (directions[i] == 'R' && directions[i + 1] == 'S')
            {
                ans += rightCount;
                ans += 1;
                rightCount = 0;
                isLeftColide = 1;
                i++;
            }
            else if (directions[i] == 'R' && directions[i + 1] == 'R')
            {
                rightCount++;
                isLeftColide = 0;
            }
            else if (directions[i] == 'S' && directions[i + 1] == 'L')
            {
                isLeftColide = 1;
                ans++;
                i++;
            }
            else if (directions[i] == 'L')
            {
                if (isLeftColide)
                {
                    ans++;
                    isLeftColide = 1;
                }
            }
         
        }
        return ans;
    }
};
// @lc code=end
