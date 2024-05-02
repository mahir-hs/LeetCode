/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> mp;
        for(char c : tasks)
            mp[c]++;
        priority_queue<int> pq;
        for(auto it : mp)
            pq.push(it.second);

        int timer = 0;

        while(!pq.empty()){
            int i = 0;
            vector<int> temp;
            while(i <= n){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
                i++;
            }
            for(int i = temp.size() - 1; i >= 0; i--){
                if(temp[i] > 1){
                    pq.push(temp[i] - 1);
                }   
            }
            timer+=pq.empty()?temp.size():n+1;
        }

        return timer;
    }
};
// @lc code=end

