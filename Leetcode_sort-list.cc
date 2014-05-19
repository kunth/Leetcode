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
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next)
            return head;
        ListNode*p1 = head, *p2 = head, *ph = NULL;
        while(p1)
        {
            p1 = p1->next;
            if(p1)
                p1 = p1->next;
            ph = p2;
            p2 = p2->next;
        }
        ph->next = NULL;
        head = sortList(head);
        p2 = sortList(p2);
        ListNode*pans = NULL;
        ListNode**ppcur = &pans;
        while(head && p2)
        {
            if(head->val < p2->val)
            {
                *ppcur = head;
                head = head->next;
            }
            else
            {
                *ppcur = p2;
                p2 = p2->next;
            }
            ppcur = &((*ppcur)->next);
        }
        if(head)
            *ppcur = head;
        else if(p2)
            *ppcur = p2;
        return pans;
    }
};
