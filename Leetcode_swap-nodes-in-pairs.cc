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

//SECOND TRIAL
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head || !head->next)
            return head;
        ListNode *l1 = head, *l2 = head->next;
        ListNode *p1 = l1, *p2 = l2, *nxt1 = NULL, *nxt2 = NULL;
        while(p1 && p2)
        {
            p1 = p1->next = p2->next;
            if(p1)
                p2 = p2->next = p1->next;
        }
        p1 = l1;
        p2 = l2;
        while(p1 && p2)
        {
            nxt1 = p1->next;
            nxt2 = p2->next;
            p2->next = p1;
            if(nxt2)
            {
                p2 = p1->next = nxt2;
                p1 = nxt1;
            }
            else
                break;
        }
        return l2;
    }
};
