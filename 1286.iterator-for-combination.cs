/*
 * @lc app=leetcode id=1286 lang=csharp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
public class CombinationIterator
{

    IList<string> ans = new List<string>();
    IList<char> temp = new List<char>();
    int idx = 0;

    public CombinationIterator(string characters, int combinationLength)
    {
        go(characters, combinationLength, 0);
    }

    public void go(string characters, int combinationLength, int len)
    {
        if (combinationLength == temp.Count)
        {
            string str = new string(temp.ToArray());
            ans.Add(str);
            return;
        }

        for (int i = len; i < characters.Length; i++)
        {
            if (temp.Count + 1 <= combinationLength)
            {
                temp.Add(characters[i]);
                go(characters, combinationLength, i + 1);
                temp.RemoveAt(temp.Count - 1);
            }
        }
    }

    public string Next()
    {
        return ans[idx++];
    }

    public bool HasNext()
    {
        return idx < ans.Count;
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj.Next();
 * bool param_2 = obj.HasNext();
 */
// @lc code=end

