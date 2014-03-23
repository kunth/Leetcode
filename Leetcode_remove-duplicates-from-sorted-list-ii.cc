//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head)
        {
            ListNode* p1 = head, *p2 = head->next;
            if(p2 && p2->val == p1->val)
            {
                while(p2 && p2->val == p1->val)
                {
                    while(p2 && p2->val == p1->val)
                        p2 = p2->next;

                    p1 = head = p2;
                    if(p1)
                        p2 = p1 ->next;
                }
            }
            while(p2)
            {
                if(p2->next && p2->val == p2->next->val)
                {
                    while(p2->next && p2->val == p2->next->val)
                    {
                        p2 = p2->next;
                    }
                    p1->next = p2->next;
                    if(p1)
                        p2 = p1->next;
                    else
                        break;
                }
                else
                {
                    p2 = p2->next;
                    p1 = p1->next;
                }
            }
        }
        return head;
    }
};
