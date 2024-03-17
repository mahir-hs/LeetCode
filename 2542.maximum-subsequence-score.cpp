/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */

// @lc code=start
class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {

        int n = nums1.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end());
        long long sum = 0;
        long long ans = 0;
        for (int i = n - 1; i >= n - k; i--)
        {
            sum = sum + v[i].second;
            pq.push(v[i].second);
        }

        ans = sum * v[n - k].first;
        cout << sum<<" "<<v[n-k].first << endl;

        for (int i = n - k - 1; i >= 0; i--)
        {
            sum = sum - pq.top() + v[i].second;
            pq.pop();
            pq.push(v[i].second);
            long long x = (sum * v[i].first);
            ans = max(ans, x);
        }
        return ans;
    }
};
// @lc code=end
