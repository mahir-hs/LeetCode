/*
 * @lc app=leetcode id=228 lang=csharp
 *
 * [228] Summary Ranges
 */

// @lc code=start
public class Solution
{
    public IList<string> SummaryRanges(int[] nums)
    {


        int start = 0;
        int end = 0;
        List<string> list = new List<string>();
        if(nums.Length==1)
        {
            list.Add(nums[0].ToString());
            return list;
        }
        for (int i = 0; i < nums.Length; i++)
        {
            if (i == 0)
            {
                start = end = nums[i];
                continue;
            }

            if (nums[i] == nums[i - 1] + 1)
            {
                end = nums[i];
            }
            else
            {
                if (start == end)
                {
                    list.Add(start.ToString());
                }
                else
                {
                    list.Add($"{start}->{end}");
                }

                start = end = nums[i];
            }

            if (i == nums.Length - 1)
            {
                if (start == end)
                {
                    list.Add(start.ToString());
                }
                else
                {
                    list.Add($"{start}->{end}");
                }
            }

        }

        return list;

    }
}
// @lc code=end

