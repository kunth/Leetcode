//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/

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
        map<int, int> dmap;
        if(head)
        {
            ListNode* p = head, *pdel = head->next;
            dmap[p->val] = 1;
            while(pdel)
            {
                if(dmap[pdel->val]==1)
                {
                    p->next = pdel->next;
                }
                else
                {
                    dmap[pdel->val] = 1;
                    p = pdel;
                }
                pdel = pdel->next;
            }
        }
        return head;
    }
};

//SECOND TRIAL
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return head;
        ListNode *pre = head, *p = head->next;
        int last = head->val;
        while(p)
        {
            if(p->val != last)
            {
                last = p->val;
                pre = p;
            }
            else
                pre->next = p->next;
            p = p->next;
        }
        return head;
    }
};
