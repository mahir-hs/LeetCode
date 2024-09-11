/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray
{
public:
    int tree[4 * (int)1e5];
    vector<int> nums;
    void init(int node, int l, int r, vector<int> &nums)
    {

        if (l == r)
        {
            tree[node] = nums[l - 1];
            return;
        }

        int mid = (l + r) / 2;

        init(node * 2, l, mid, nums);
        init(node * 2 + 1, mid + 1, r, nums);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void updateTree(int node, int l, int r, int index, int val)
    {

        if (l == r)
        {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid)
            updateTree(node * 2, l, mid, index, val);
        else
            updateTree(node * 2 + 1, mid + 1, r, index, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int l, int r, int left, int right)
    {

        if (l > right || r < left)
            return 0;

        if (l >= left && r <= right)
            return tree[node];

        int mid = (l + r) / 2;
        int q1 = query(node * 2, l, mid, left, right);
        int q2 = query(node * 2 + 1, mid + 1, r, left, right);

        return q1 + q2;
    }
    NumArray(vector<int> &nums) : nums(nums)
    {
        int n = (int)nums.size();
        init(1, 1, n, nums);
    }

    void update(int index, int val)
    {
        index++;
        updateTree(1, 1, nums.size(), index, val);
    }

    int sumRange(int left, int right)
    {
        left++;
        right++;
        return query(1, 1, nums.size(), left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
