/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> v;
    string s;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        s += to_string(root->val);
        s += "->";
        if (root->left == nullptr and root->right == nullptr)
        {
            s.pop_back();
            s.pop_back();
            v.push_back(s);
            int k = to_string(root->val).size();
            while (k--)
                s.pop_back();
            return;
        }
        dfs(root->left);
        dfs(root->right);
        s.pop_back();
        s.pop_back();
        int k = to_string(root->val).size();
        while (k--)
            s.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {

        dfs(root);
        // for (auto k : v)
        //     cout << k << endl;
        return v;
    }
};
// @lc code=end
