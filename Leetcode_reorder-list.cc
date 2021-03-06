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

//SECOND TRIAL
class Solution {
private:
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        ListNode *p = head, *pre = NULL, *nxt = NULL;
        while(p)
        {
            nxt = p->next;
            p->next = pre;
            pre = p;
            p = nxt;
        }
        return pre;
    }
public:
    void reorderList(ListNode *head) {
        if(!head || !head->next)
            return;
        ListNode*p1 = head, *p2 = head, *pre = NULL, *nxt1 = NULL, *nxt2 = NULL;
        while(p1)
        {
            p1 = p1->next;
            pre = p2;
            if(p1)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        p2 = pre->next;
        pre->next = NULL;
        p2 = reverseList(p2);
        p1 = head;
        while(p1 && p2)
        {
            nxt1 = p1->next;
            nxt2 = p2->next;
            p1->next = p2;
            p1 = p2->next = nxt1;
            p2 = nxt2;
        }
    }
};


//Yeah, try it again
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* breakList(ListNode* head) {
        ListNode*fast = head, *slow = head;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        fast = slow->next;
        slow->next = NULL;
        return fast;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode*cur = head, *pre = NULL, *nxt = NULL;
        while(cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
public:
    void reorderList(ListNode *head) {
        if(!head || !head->next)
            return;
        ListNode* slow = breakList(head);
        slow = reverseList(slow);
        ListNode* front = head, *nxt1 = NULL, *nxt2 = NULL;
        while(front && slow) {
            nxt1 = front->next;
            nxt2 = slow->next;
            front->next = slow;
            slow->next = nxt1;
            front = nxt1;
            slow = nxt2;
        }
    }
};
