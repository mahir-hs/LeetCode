/*
 * @lc app=leetcode id=2967 lang=cpp
 *
 * [2967] Minimum Cost to Make Array Equalindromic
 */

// @lc code=start
class Solution
{
public:
    bool is_palindrome(long long n)
    {
        long long temp = n;
        string origin = to_string(n);
        reverse(origin.begin(), origin.end());
        n = stoll(origin);
        if (temp == n)
            return true;
        else
            return false;
    }
    long long calculate(vector<int> nums, int n)
    {
        long long cost = 0;
        for (auto x : nums)
        {
            cost += (abs(x - n));
        }
        return cost;
    }
    long long greater(long long n)
    {
        while (!is_palindrome(n))
        {
            n++;
        }
        return n;
    }
    long long smaller(long long n)
    {
        while (!is_palindrome(n))
        {
            n--;
        }
        return n;
    }
    long long minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            if (is_palindrome(nums[0]))
                return 0;
            else
                return 1;
        }
        sort(nums.begin(), nums.end());
        int mid;
        if (n & 1)
        {
            mid = nums[n / 2];
        }
        else
        {
            mid = (nums[n / 2] + nums[(n + 1) / 2]) / 2;
        }
        long long mini = INT_MAX;
        long long great = greater(mid);
        long long small = smaller(mid);
        long long res1 = calculate(nums, great);
        long long res2 = calculate(nums, small);
        return res1 < res2 ? res1 : res2;
    }
};
// @lc code=end
