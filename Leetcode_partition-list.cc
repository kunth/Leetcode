class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head)
            return NULL;
        ListNode *new_head = head, *p = head, *bigger_head = NULL, *pre=NULL, *bigger_cur=NULL;
        while(new_head && new_head->val>=x)
            new_head = new_head->next;
        //all elems >= x
        if(!new_head)
            return head;
        while(p)
        {
            if(p->val<x)
            {
                pre = p;
                p = p->next;
            }
            else
            {
                if(!bigger_head)
                    bigger_cur = bigger_head = p;
                else
                {
                    bigger_cur->next = p;
                    bigger_cur = bigger_cur->next;
                }
                p = p->next;
                while(p && p->val >= x)
                {
                    bigger_cur = p;
                    p = p->next;
                }
                if(p)
                {
                    if(!pre)
                        pre = p;
                    else
                    {
                        pre->next = p;
                        pre = p;
                    }
                    p = p->next;
                }
            }
        }
        if(bigger_cur)
            bigger_cur->next = NULL;
        if(pre)
            pre->next = bigger_head;
        return new_head;
    }
};


//SECOND SOLUTION
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head)
            return NULL;
        ListNode *newHead = NULL, *newTail=NULL, *biggerHead = NULL, *q = NULL, *p = head;
        while(p)
        {
            if(p->val<x)
            {
                if(!newHead)
                    newTail = newHead = p;
                else
                {
                    newTail->next = p;
                    newTail = p;
                }
                p = p->next;
            }
            else
            {
                if(!biggerHead)
                    q = biggerHead = p;
                else
                {
                    q->next = p;
                    q = q->next;
                }
                p = p->next;
                while(p && p->val>=x)
                {
                    q->next = p;
                    q = p;
                    p = p->next;
                }
            }
        }
        if(!newHead || !biggerHead)
            return head;
        newTail->next = biggerHead;
        q->next = NULL;
        return newHead;
    }
};
