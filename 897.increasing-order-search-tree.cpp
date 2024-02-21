/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    void dfs(TreeNode *root, TreeNode *&ans)
    {
        if (root == nullptr)
            return;

        if (root->left)
            dfs(root->left, ans);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        dfs(root->right, ans);
    }
    TreeNode *increasingBST(TreeNode *root)
    {

        TreeNode *temp = new TreeNode(-1);
        TreeNode *ans = temp;
        dfs(root, ans);
        return temp->right;
    }
};
// @lc code=end
