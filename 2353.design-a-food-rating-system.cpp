/*
 * @lc app=leetcode id=2353 lang=cpp
 *
 * [2353] Design a Food Rating System
 */

// @lc code=start
class FoodRatings
{
    map<string, pair<string, int>> fc;
    map<string, map<int, set<string>>> cf;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            fc[foods[i]] = {cuisines[i], ratings[i]};
            cf[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating)
    {
        pair<string, int> now = fc[food];
        fc[food] = {now.first, newRating};

        cf[now.first][now.second].erase(food);

        if (cf[now.first][now.second].empty())
            cf[now.first].erase(now.second);

        cf[now.first][newRating].insert(food);
    }

    string highestRated(string cuisine)
    {
        return *cf[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end
