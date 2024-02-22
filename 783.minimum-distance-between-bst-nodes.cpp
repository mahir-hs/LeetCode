/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    int ans = INT_MAX;
    vector<int> v;
    void go(TreeNode *root)
    {
        if (!root)
            return;
        v.push_back(root->val);
        go(root->left);
        go(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        go(root);
        sort(v.begin(), v.end());
     
        for (int i = 0; i < v.size() - 1; i++)
        {
            ans = min(ans, abs(v[i] - v[i + 1]));
        }
        return ans;
    }
};
// @lc code=end
