/*
 * @lc app=leetcode id=2349 lang=cpp
 *
 * [2349] Design a Number Container System
 */

// @lc code=start
class NumberContainers
{
public:
    unordered_map<long long, long long> arr;
    unordered_map<long long, set<long long>> idx;
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        long long val = arr[index];
        if (idx[val].empty() == false)
            idx[val].erase(index);
        idx[number].insert(index);
        arr[index] = number;
    }

    int find(int number)
    {
        if (idx[number].empty())
            return -1;
        return *idx[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end
