/*
 * @lc app=leetcode id=1123 lang=csharp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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

    private (TreeNode Node, int MaxDepth) DFS(TreeNode node, int depth)
    {
        if (node == null)
            return (node, depth - 1);
        var left = DFS(node.left, depth + 1);
        var right = DFS(node.right, depth + 1);
        if (left.MaxDepth > right.MaxDepth)
            return (left.Node, left.MaxDepth);
        else if (left.MaxDepth < right.MaxDepth)
            return (right.Node, right.MaxDepth);
        else
            return (node, right.MaxDepth);
    }

    public TreeNode LcaDeepestLeaves(TreeNode root)
    {
        var newRoot = DFS(root, 0);
        return newRoot.Node;
    }
}
// @lc code=end

