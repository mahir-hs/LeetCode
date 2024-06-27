/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap
{
public:
    unordered_map<string, map<int, string>> mp;
    TimeMap()
    {
        mp = unordered_map<string, map<int, string>>();
    }

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        string ans = "";
        if ((mp.find(key) != mp.end()) && (!mp[key].empty()) && (mp[key].begin())->first <= timestamp)
        {
            for (auto it = mp[key].rbegin(); it != mp[key].rend(); it++)
            {
                if (it->first <= timestamp)
                {
                    ans = it->second;
                    break;
                }
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
