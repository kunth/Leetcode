http://oj.leetcode.com/problems/reorder-list/

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode*pre=NULL, *cur=head, *next=NULL;
        while(cur)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    void reorderList(ListNode *head) {
        if(head)
        {
            ListNode *p1 = head, *p2 = head, *nxt1 = NULL, *nxt2 = NULL;
            while(p2 && p2->next)
            {
                p1 = p1->next;
                p2 = p2->next;
                if(p2)
                    p2 = p2->next;
            }
            p2 = p1->next;
            p1->next = NULL;
            p1 = head;
            p2 = reverseList(p2);
            while(p1 && p2)
            {
                nxt1 = p1->next;
                nxt2 = p2->next;
                p1->next = p2;
                p2->next = nxt1;
                p1 = nxt1;
                p2 = nxt2;
            }
        }
    }
};
