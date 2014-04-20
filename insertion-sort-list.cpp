class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(!head)
            return head;
        ListNode* virtual_head = new ListNode(-1<<31), *p = head->next, *cmp = NULL, *nxt = NULL, *tail = head;
        virtual_head->next = head;
        while(p)
        {
            nxt = p->next;
            cmp = virtual_head;
            while(cmp!=tail && cmp->next->val < p->val)
                cmp = cmp->next;
            if(cmp != tail)
            {
                p->next = cmp->next;
                cmp->next = p;
            }
            else
            {
                tail = tail->next = p;
            }
            p = nxt;
        }
        tail->next = NULL;
        return virtual_head->next;
    }
};
