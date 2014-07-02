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

//Solution Two
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !k || !head->next)
            return head;
        int len = 0;
        ListNode *p = head;
        while(p)
        {
            ++len;
            p = p->next;
        }
        k %= len;
        if(!k)
            return head;
        k = len-k;
        ListNode *ret = head, *pre = NULL;
        while(k)
        {
            pre = ret;
            ret = ret->next;
            --k;
        }
        pre->next = NULL;
        p = ret;
        while(p->next)
            p = p->next;
        p->next = head;
        return ret;
    }
};
