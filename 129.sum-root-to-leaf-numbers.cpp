/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    string s;
    int ans = 0;

    void dfs(TreeNode* root)
    {

        if (root == nullptr)
            return;

        s += to_string(root->val);

        if (!root->left && !root->right)
        {
            ans += stoi(s);
            s.pop_back();
            return;
        }

        if (root->left) 
            dfs(root->left);
        if (root->right)        
            dfs(root->right);

        s.pop_back();
    }
    int sumNumbers(TreeNode *root)
    {

        dfs(root);
        return ans;
    }
};
// @lc code=end
