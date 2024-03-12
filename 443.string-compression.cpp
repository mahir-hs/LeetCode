/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution
{
public:
    int compress(vector<char> &chars)
    {

        int ans = 0, cnt = 0;
        char last = '!';
        int i = 0;

        for (auto k : chars)
        {
            if (last == '!')
            {
                cnt++;
                last = k;
                continue;
            }

            if (last == k)
            {
                cnt++;
            }
            else
            {
                if (cnt == 1)
                {
                    chars[i++] = last;
                    ans++;
                }
                else
                {
                    string s = to_string(cnt);
                    ans += s.size();
                    ans++;
                    chars[i++] = last;
                    for (auto x : s)
                    {
                        chars[i++] = x;
                    }
                }
                last = k;
                cnt = 1;
            }
        }
        if (cnt == 1)
        {
            chars[i++] = last;
            ans++;
        }
        else
        {
            string s = to_string(cnt);
            ans += s.size();
            ans++;
            chars[i++] = last;
            for (auto x : s)
            {
                chars[i++] = x;
            }
        }
        return ans;
    }
};
// @lc code=end
