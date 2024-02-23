/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start

struct node
{
    int val;
    int cnt;
    node *left, *right;
    node(int x) : val(x), cnt(1), left(nullptr), right(nullptr) {}
};
class KthLargest
{
private:
    node *root = nullptr;
    int k;

    node *insert(node *root, int num)
    {
        if (!root)
            return new node(num);
        if (root->val < num)
            root->right = insert(root->right, num);
        else
            root->left = insert(root->left, num);
        root->cnt++;
        return root;
    }

    int search(node *root, int k)
    {
        if (!root)
            return 0;
        int right = 0;
        if (root->right)
        {
            right = root->right->cnt;
        }

        if (right + 1 == k)
            return root->val;
        else if (right + 1 > k)
        {
            return search(root->right, k);
        }
        k -= right + 1;
        return search(root->left, k);
    }

public:
    KthLargest(int k, vector<int> &nums)
    {
        for (auto num : nums)
            this->root = this->insert(this->root, num);
        this->k = k;
    }

    int add(int val)
    {
        this->root = this->insert(this->root, val);
        return search(this->root, this->k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
