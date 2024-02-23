/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    vector<int> left, right;
    void go(TreeNode *root)
    {
        if (!root)
        {
            left.push_back(-1);
            return;
        }

        left.push_back(root->val);
        go(root->left);
        go(root->right);
    }
    void go2(TreeNode *root)
    {
        if (!root)
        {
            right.push_back(-1);
            return;
        }

        right.push_back(root->val);
        go2(root->right);
        go2(root->left);
    }
    bool isSymmetric(TreeNode *root)
    {

        go(root->left);
        go2(root->right);
        // for (auto k : left)
        //     cout << k << " ";
        // cout << endl;
        // for (auto k : right)
        //     cout << k << " ";
        // cout << endl;

        return (left == right);
    }
};
// @lc code=end
