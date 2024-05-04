/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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

    int ans = 0;
    void dfs(TreeNode *root, int mx)
    {
        if (!root)
            return;

        if (root->val >= mx)
        {
            ans++;
        }
        mx = max(mx, root->val);
        dfs(root->left, mx);
        dfs(root->right, mx);

        return;
    }
    int goodNodes(TreeNode *root)
    {

        dfs(root, root->val);
        return ans;
    }
};
// @lc code=end
