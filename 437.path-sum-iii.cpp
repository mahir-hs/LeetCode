/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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

    void dfs2(TreeNode *root, long long targetSum, long long cnt)
    {

        if (!root)
            return;

        if (cnt + root->val == targetSum)
            ans++;
        if (root->left)
            dfs2(root->left, targetSum, cnt + root->val);
        if (root->right)
            dfs2(root->right, targetSum, cnt + root->val);
    }
    void dfs1(TreeNode *root, long long targetSum)
    {

        if (!root)
            return;

        dfs2(root, targetSum, 0LL);

        dfs1(root->left, targetSum);
        dfs1(root->right, targetSum);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        dfs1(root, targetSum);
        return ans;
    }
};
// @lc code=end
