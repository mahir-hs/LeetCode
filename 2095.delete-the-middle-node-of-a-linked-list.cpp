/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode *deleteMiddle(ListNode *head)
    {

        if (!head || !head->next)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        int i = 0;
        while (fast && fast->next)
        {
            if (i > 0)
                slow = slow->next;
            fast = fast->next->next;
            i++;
        }
        slow->next = slow->next->next;
        return head;
    }
};
// @lc code=end
