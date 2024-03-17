/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */

// @lc code=start
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        deque<int> d;
        priority_queue<int, vector<int>, greater<int>> left,right;
        for(auto c: costs) {
           d.push_back(c);
        }
        // cout<<"d: "<<d.size()<<endl;
        int x = d.size();
        for(int i = 0; i < min(candidates, x); i++) {
            left.push(d.front());
            d.pop_front();
        }
        x = d.size();
        for(int i = 0; i < min(candidates, x); i++) {
            right.push(d.back());
            d.pop_back();
        }
        long long ans = 0;
        // cout<<"left: "<<left.size()<<" right: "<<right.size()<<" d: "<<d.size()<<endl;
        while(k--) {
            if(!left.empty() and !right.empty()) {
                if (left.top() <= right.top())
                {
                    ans += left.top();
                    left.pop();
                    if (d.size())
                    {
                        left.push(d.front());
                        d.pop_front();
                    }
                }
                else
                {
                    ans += right.top();
                    right.pop();
                    if (d.size())
                    {
                        right.push(d.back());
                        d.pop_back();
                    }
                }
            }
            else if(!left.empty()) {
                ans += left.top();
                left.pop();
            }
            else if(!right.empty()) {
                ans += right.top();
                right.pop();
            }
          
        }
        return ans;
    }
};
// @lc code=end

// [ 25, 20, 60, 21, 11, 99, 55, 22, 83, 62, 12, 63, 100, 41, 33, 92, 13, 92, 58, 85, 61, 93, 5, 46, 26, 25, 36, 27, 12, 30, 13, 52, 30 ]\n8 \n22