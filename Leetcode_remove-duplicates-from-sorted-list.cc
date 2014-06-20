//http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//SECOND TRIAL
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return head;
        ListNode *pre = head, *p = head->next;
        while(p)
        {
            if(p->val != pre->val)
                pre = p;
            else
                pre->next = p->next;
            p = p->next;
        }
        return head;
    }
};
