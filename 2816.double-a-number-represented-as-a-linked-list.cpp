/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void multiply(string &s)
    {
        reverse(s.begin(), s.end());
        int carry = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int sum = (s[i] - '0') * 2 + carry;
            s[i] = (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry)
            s += '1';
        reverse(s.begin(), s.end());
    }
    ListNode *doubleIt(ListNode *head)
    {

        ListNode *temp = head;
        string sum;
        int cnt = 0;
        while (temp != nullptr)
        {
            sum += to_string(temp->val);
            temp = temp->next;
            cnt++;
        }

        multiply(sum);

        if(sum.size() > cnt)
        {
            ListNode *x = new ListNode();
            x->val = 0;
            x->next = head;
            head = x;
        }

        temp = head;
        for (int i = 0; i < sum.size(); i++)
        {
            temp->val = sum[i] - '0';
            temp = temp->next;
        }
        return head;
    }
};
// @lc code=end
