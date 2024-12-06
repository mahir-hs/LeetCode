/*
 * @lc app=leetcode id=687 lang=csharp
 *
 * [687] Longest Univalue Path
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    int go(TreeNode root,ref int ans)
    {
        if (root == null) return 0;
        int left = go(root.left, ref ans);
        int right = go(root.right, ref ans);
        if (root.left == null || root.left.val != root.val) left = 0;
        if (root.right == null || root.right.val != root.val) right = 0;
        ans = Math.Max(ans, left + right);
        return Math.Max(left, right) + 1;
    }
    public int LongestUnivaluePath(TreeNode root)
    {
        int ans = 0;
        go(root, ref ans);
        return ans;
    }
}
// @lc code=end

