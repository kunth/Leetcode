//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head)
        {
            ListNode* p1 = head, *p2 = head->next;
            if(p2 && p2->val == p1->val)
            {
                while(p2 && p2->val == p1->val)
                {
                    while(p2 && p2->val == p1->val)
                        p2 = p2->next;

                    p1 = head = p2;
                    if(p1)
                        p2 = p1 ->next;
                }
            }
            while(p2)
            {
                if(p2->next && p2->val == p2->next->val)
                {
                    while(p2->next && p2->val == p2->next->val)
                    {
                        p2 = p2->next;
                    }
                    p1->next = p2->next;
                    if(p1)
                        p2 = p1->next;
                    else
                        break;
                }
                else
                {
                    p2 = p2->next;
                    p1 = p1->next;
                }
            }
        }
        return head;
    }
};

//SECOND TRIAL
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return head;
        ListNode *pre = head, *mid = head, *cur = head->next;
        while(cur)
        {
            if(cur->val != mid->val)
            {
                pre = mid;
                mid = cur;
                cur = cur->next;
            }
            else
            {
                if(pre==mid)
                {
                    while(cur && cur->val == mid->val)
                        cur = cur->next;
                    if(cur)
                    {
                        head = pre = mid = cur;
                        cur = cur->next;
                    }
                    else
                        return NULL;
                }
                else
                {
                    while(cur && cur->val == mid->val)
                        cur = cur->next;
                    if(cur)
                    {
                        mid = cur;
                        pre->next = mid;
                        cur = cur->next;
                    }
                    else
                        pre->next = NULL;
                }
            }
        }
        return head;
    }
};
