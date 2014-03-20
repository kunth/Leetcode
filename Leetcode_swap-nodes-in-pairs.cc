class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head)
        {
            return head;
        }
        ListNode *p1 = head, *p2 = head->next, *cur=head;
        if(!p2)
        {
            return head;
        }
        head = p2;
        p1->next = p2->next;
        p2->next = p1;
        cur = p1;
        while(p1->next)
        {
            p1 = p1->next;
            p2 = p1->next;
            if(p2)
            {
                p1->next = p2->next;
                p2->next = p1;
                cur->next = p2;
                cur = p1;
            }
        }
        return head;
    }
};
