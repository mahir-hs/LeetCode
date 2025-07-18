/*
 * @lc app=leetcode id=3297 lang=csharp
 *
 * [3297] Count Substrings That Can Be Rearranged to Contain a String I
 */

// @lc code=start
public class Solution
{

    private bool CountCompare(int[] charCountWord1, int[] charCountWord2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (charCountWord1[i] < charCountWord2[i])
            {
                return false;
            }
        }
        return true;
    }
    public long ValidSubstringCount(string word1, string word2)
    {

        if (word1.Length < word2.Length)
            return 0;

        long count = 0;
        int[] charCountWord2 = new int[26];
        foreach (char c in word2)
        {
            charCountWord2[c - 'a']++;
        }

        int n = word1.Length;
        int i = 0, j = 0;
        int[] charCountWord1 = new int[26];
        while (j < n)
        {

            charCountWord1[word1[j] - 'a']++;

            while (CountCompare(charCountWord1, charCountWord2) && i <= j)
            {
                count += n - j;
                charCountWord1[word1[i] - 'a']--;
                i++;
            }
            j++;
        }

        return count;
    }
}
// @lc code=end

// The function ValidSubstringCount is expected to count the number of substrings in word1 that can be rearranged to form word2.
// The implementation is not provided, but it would typically involve checking all substrings of word1
// and determining if they can be rearranged to match the character counts of word2.
// This could involve using frequency counts of characters in both strings and comparing them.
// The expected time complexity would likely be O(n^2 * m) where n is the length of word1 and m is the length of word2,
// due to the need to check each substring of word1 against the character counts of word2
// using a sliding window or similar approach to optimize the substring checks.

