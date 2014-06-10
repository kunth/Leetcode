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
    bool hasCycle(ListNode *head) {
        ListNode *p1, *p2;
        p1 = head;
        if(!head)
            return false;
        p2 = p1->next;
        while(p1 && p2 && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if(p2)
                p2=p2->next;
        }
        if(!p1 || !p2)
        {
            return false;
        }
        return true;
    }
};

//SECOND TRIAL
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode*p = head, *q = head;
        do{
            p = p->next;
            if(p)
                p = p->next;
            q = q->next;
        }while(p && p!=q);
        return p;
    }
};
