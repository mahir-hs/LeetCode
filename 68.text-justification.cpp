/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution
{
public:
    string justify(vector<string> &temp, int maxWidth, int len)
    {
        if (temp.size() == 1)
        {

            string s = temp.back();
            int left = maxWidth - len;
            if (left > 0)
            {
                for (int j = 0; j < left; j++)
                {
                    s += " ";
                }
            }
            return s;
        }
        int left = maxWidth - len;
        int spaces = left / (temp.size() - 1);
        int extra = left % (temp.size() - 1);

        string s;
        for (int j = 0; j < temp.size(); j++)
        {
            s += temp[j];
            if (j < temp.size() - 1)
            {
                for (int k = 0; k < spaces; k++)
                {
                    s += " ";
                }
                if (extra > 0)
                {
                    extra--;
                    s += " ";
                }
            }
        }
        return s;
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        vector<string> temp;
        int len = 0;
        for (int i = 0; i < words.size(); i++)
        {

            if (i == words.size() - 1)
            {
                int x = temp.size();
                

                if (len + words[i].size() + x <= maxWidth)
                {
                    temp.push_back(words[i]);
                    len += words[i].size();
                    string s;
                    int space = maxWidth - len;
                    for (int j = 0; j < temp.size(); j++)
                    {
                        s += temp[j];
                        if (space > 0)
                        {
                            s += " ";
                            space--;
                        }
                    }
                    for (int j = 0; j < space; j++)
                    {
                        s += " ";
                    }
                    ans.push_back(s);
                    return ans;
                }
                else
                {
                    string result = justify(temp, maxWidth, len);
                    len = words[i].size();
                    ans.push_back(result);

                    string s = words[i];
                    int left = maxWidth - len;
                    for (int j = 0; j < left; j++)
                    {
                        s += " ";
                    }
                    ans.push_back(s);
                }
            }
            else
            {

                int x = temp.size();
                if (len + words[i].size() + x <= maxWidth)
                {

                    temp.push_back(words[i]);
                    len += words[i].size();
                }
                else
                {
                    string result = justify(temp, maxWidth, len);
                    temp.clear();
                    temp.push_back(words[i]);
                    len = words[i].size();
                    ans.push_back(result);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
