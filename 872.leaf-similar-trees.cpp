/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    vector<int> first, second;
    void go(TreeNode *root, vector<int> &x)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr and root->right == nullptr)
        {
            x.push_back(root->val);
            return;
        }
        go(root->left, x);
        go(root->right, x);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        go(root1, first);
        go(root2, second);
        return (first == second);
    }
};
// @lc code=end
