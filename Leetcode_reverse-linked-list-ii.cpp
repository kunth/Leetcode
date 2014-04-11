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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head || m==n)
            return head;
        ListNode *front = NULL, *p = head, *rear = NULL, *pre = NULL, *cur = NULL, *nxt = NULL;
        int i;
        for(i = 1; i<m; ++i)
        {
            front = p;
            p = p->next;
        }
        cur = p;
        for(; i<n; ++i)
        {
            p = p->next;
        }
        rear = pre = p->next;
        while(cur != rear)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        if(m==1)
            return p;
        front->next = p;
        return head;
    }
};
