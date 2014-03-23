//http://oj.leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        else
        {
            ListNode* head = NULL, *p = NULL;
            if(l1->val <= l2->val)
            {
                head = l1;
                l1 = l1->next;
            }
            else
            {
                head = l2;
                l2 = l2->next;
            }
            p = head;
            while(l1 && l2)
            {
                if(l1->val <= l2->val)
                {
                    p->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }
            if(l1)
            {
                p->next = l1;
            }
            else
            {
                p->next = l2;
            }
            return head;
        }
    }
};
