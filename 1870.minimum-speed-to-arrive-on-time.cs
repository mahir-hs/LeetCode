/*
 * @lc app=leetcode id=1870 lang=csharp
 *
 * [1870] Minimum Speed to Arrive on Time
 */

// @lc code=start
public class Solution
{

    public bool possible(int[] dist, double hour, int speed)
    {
        double time = 0;
        for (int i = 0; i < dist.Length - 1; i++)
        {
            time += Math.Ceiling((double)dist[i] / speed);
        }
        time += (double)dist[dist.Length - 1] / speed;
        return time <= hour;
    }
    public int MinSpeedOnTime(int[] dist, double hour)
    {

        if (dist.Length > Math.Ceiling(hour))
            return -1;

        int l = 1, r = 10000000;
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (possible(dist, hour, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
}
// @lc code=end

