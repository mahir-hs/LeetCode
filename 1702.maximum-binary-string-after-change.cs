/*
 * @lc app=leetcode id=1702 lang=csharp
 *
 * [1702] Maximum Binary String After Change
 */

// @lc code=start
public class Solution
{
    public string MaximumBinaryString(string binary)
    {

        int idx = -1, zero = 0;
        for (int i = 0; i < binary.Length; i++)
        {
            if (binary[i] == '0')
            {
                zero++;
                if (idx == -1)
                {
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            return binary;
        }
        int len = idx + (zero - 1);
        var ans = new System.Text.StringBuilder(binary.Length);

        for (int i = 0; i < binary.Length; i++)
        {
            if (i == len)
            {
                ans.Append('0');
            }
            else
            {
                ans.Append('1');
            }
        }

        return ans.ToString();

    }
}
// @lc code=end

