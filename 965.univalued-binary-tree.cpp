/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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
    set<int> s;
    void go(TreeNode *root)
    {
        if (root == nullptr)
            return;
        s.insert(root->val);
        go(root->left);
        go(root->right);
    }
    bool isUnivalTree(TreeNode *root)
    {

        go(root);
        if (s.size() > 1)
            return false;
        return true;
    }
};
// @lc code=end
