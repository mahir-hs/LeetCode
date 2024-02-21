/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    string s = "";
    int ans = 0;
    void dfs(TreeNode *root)
    {

        if (root == nullptr)
        {
            // cout << s << ": " << stoi(s, nullptr, 2) << endl;
            ans += stoi(s, nullptr, 2);
            return;
        }

        s += to_string(root->val);
        if (!root->left and !root->right)
        {
            dfs(nullptr);
            s.pop_back();
            return;
        }
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
        s.pop_back();
        return;
    }
    int sumRootToLeaf(TreeNode *root)
    {

        dfs(root);
        return ans;
    }
};
// @lc code=end
//       0
//    1     0
//   0 x  0   0
//  x x  x 1 x x
//        x 1