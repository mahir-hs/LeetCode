/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    void go(TreeNode *&ans, TreeNode *root1, TreeNode *root2)
    {
        if (!root1 and !root2)
        {
            return;
        }
        else if (root1 and !root2)
        {
            TreeNode *node(new TreeNode(root1->val));
            ans = node;
            go(ans->left, root1->left, root2);
            go(ans->right, root1->right, root2);
        }
        else if (!root1 and root2)
        {
            TreeNode *node(new TreeNode(root2->val));
            ans = node;
            go(ans->left, root1, root2->left);
            go(ans->right, root1, root2->right);
        }
        else
        {
            TreeNode *node(new TreeNode(root1->val + root2->val));
            ans = node;
            go(ans->left, root1->left, root2->left);
            go(ans->right, root1->right, root2->right);
        }
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {

        TreeNode *ans(nullptr);
        go(ans, root1, root2);
        return ans;
    }
};
// @lc code=end
