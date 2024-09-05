/*
 * @lc app=leetcode id=1061 lang=csharp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
public class Solution
{
    public string SmallestEquivalentString(string s1, string s2, string baseStr)
    {
        var dsu = new DSU(26);
        for (int i = 0; i < s1.Length; i++)
        {
            dsu.Union(s1[i] - 'a', s2[i] - 'a');
        }
        var sb = new StringBuilder();
        foreach (var c in baseStr)
        {
            sb.Append((char)(dsu.Find(c - 'a') + 'a'));
        }
        return sb.ToString();
    }

    public class DSU
    {
        private int[] parent;

        public DSU(int n)
        {
            parent = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        public void Union(int x, int y)
        {
            var xRoot = Find(x);
            var yRoot = Find(y);
            if (xRoot == yRoot)
            {
                return;
            }
            parent[Math.Max(xRoot, yRoot)] = Math.Min(xRoot, yRoot);
        }

        public int Find(int x)
        {
            if (parent[x] != x)
            {
                parent[x] = Find(parent[x]);
            }
            return parent[x];
        }
    }
}
// @lc code=end
