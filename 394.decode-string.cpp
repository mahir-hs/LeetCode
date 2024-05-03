/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:

    string decodeString(string s)
    {

        stack<int> num;
        stack<char> st;
        bool ok = false;

        for (int i = 0; i < s.length(); i++)
        {

            if (isdigit(s[i]))
            {

                if(ok==false)
                {
                    num.push(s[i] - '0');
                    ok = true;
                }
                else
                {
                    int x = num.top();
                    num.pop();
                    num.push(x * 10 + (s[i] - '0'));
                }
            }
            else
            {
                if(s[i]==']')
                {
                    ok = false;
                    string temp;
                    while(st.top()!='[')
                    {
                        temp = st.top() + temp;
                        st.pop();
                    }
                    st.pop();
                    int x = num.top();
                    num.pop();
                    for(int j = 0; j < x; j++)
                    {
                        for(int k = 0; k < temp.length(); k++)
                        {
                            st.push(temp[k]);
                        }
                    }
                }
                else
                {
                    ok = false;
                    st.push(s[i]);
                }
            }
        }

        string ans = "";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
// @lc code=end
