/*
 * @lc app=leetcode id=1963 lang=csharp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
public class Solution
{
    public int MinSwaps(string s)
    {
        int ans = 0;
        var stack = new Stack<char>();
        for (int i = 0; i < s.Length; i++)
        {

            if (s[i] == '[')
            {
                stack.Push(s[i]);
            }
            if (s[i] == ']' && stack.Count > 0 && stack.Peek() == '[')
            {
                stack.Pop();
            }
        }

        return (stack.Count + 1) / 2;
    }
}
// @lc code=end

