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

//SECOND TRIAL
class Solution {
private:
    ListNode* reverse(ListNode* head)
    {
        ListNode *pre = NULL, *nxt = NULL, *cur = head;
        while(cur)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head || m==n)
            return head;
        ListNode *pre = head, *end = head, *nxt = NULL, *ret = NULL;
        if(m>1)
        {
            for(int i = 1; i<m-1; ++i)
                pre = pre->next;
            ret = head;
        }
        for(int i = 1; i<n; ++i)
            end = end->next;
        if(!ret)
            ret = end;

        nxt = end->next;
        end->next = NULL;

        if(ret!=head)
        {
            reverse(head);
            head->next = nxt;
        }
        else
        {
            end = pre->next;
            pre->next = reverse(pre->next);
            end->next = nxt;
        }
        return ret;
    }
};
