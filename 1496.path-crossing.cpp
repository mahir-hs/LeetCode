/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
class Solution
{
public:
    bool isPathCrossing(string path)
    {
        int x = 0, y = 0;
        map<pair<int, int>, int> m;
        m[{0, 0}] = 1;

        for (auto k : path)
        {

            if (k == 'N')
            {
                y++;
            }
            else if (k == 'S')
            {
                y--;
            }
            else if (k == 'E')
            {
                x++;
            }
            else
                x--;

            if (m[{x, y}])
                return true;
            m[{x, y}] = 1;
        }
        return false;
    }
};
// @lc code=end
