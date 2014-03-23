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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head)
            return NULL;
        int len = 0;
        ListNode* p = head, *q = head, *newhead = head;
        while(p)
        {
            ++len;
            p = p->next;
        }
        k %= len;
        if(!k)
            return head;
        p = head;
        len = 0;
        while(len++ < k)
        {
            p = p->next;
        }
        while(p->next)
        {
            p = p->next;
            q = q->next;
        }
        newhead = q->next;
        q->next = NULL;
        p->next = head;
        return newhead;
    }
};
