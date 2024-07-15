/*
 * @lc app=leetcode id=290 lang=csharp
 *
 * [290] Word Pattern
 */

// @lc code=start
public class Solution
{
    public bool WordPattern(string pattern, string s)
    {


        string[] arr = s.Split(' ');
        if (pattern.Length != arr.Length)
            return false;
        Dictionary<char, string> dict = new Dictionary<char, string>();
        Dictionary<string, char> dict2 = new Dictionary<string, char>();

        for (int i = 0; i < pattern.Length; i++)
        {
            if (dict.ContainsKey(pattern[i]) && dict[pattern[i]] != arr[i])
                return false;
            if (dict2.ContainsKey(arr[i]) && dict2[arr[i]] != pattern[i])
                return false;
            dict[pattern[i]] = arr[i];
            dict2[arr[i]] = pattern[i];
        }

        return true;

    }
}
// @lc code=end

