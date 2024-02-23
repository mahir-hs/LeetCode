/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool go(TreeNode *root, TreeNode *x)
    {
        if (!root && !x)
            return 1;
        if (!root || !x)
            return 0;

        if (root->val != x->val)
        {
            return 0;
        }

        bool left = go(root->left, x->left);
        bool right = go(root->right, x->right);
        return (left & right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return 0;
        if (go(root, subRoot))
            return 1;
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return (left | right);
    }
};
// @lc code=end
