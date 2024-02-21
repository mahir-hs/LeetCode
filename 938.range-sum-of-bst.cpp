/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int go(TreeNode *root, int low, int high)
    {
        if (root->left == nullptr and root->right == nullptr)
            return 0;
        int sum = 0;
        if (root->left != nullptr)
            sum += ((root->left->val >= low and root->left->val <= high) ? root->left->val : 0) + go(root->left, low, high);
        if (root->right != nullptr)
            sum += ((root->right->val >= low and root->right->val <= high) ? root->right->val : 0) + go(root->right, low, high);
        return sum;
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return go(root, low, high) + ((root != nullptr and root->val >= low and root->val <= high) ? root->val : 0);
    }
};
// @lc code=end
