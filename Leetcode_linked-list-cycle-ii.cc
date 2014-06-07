//http://oj.leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int>lm;
        while(head)
        {
            if(lm[head]==0)
            {
                lm[head] = 1;
                head = head->next;
            }
            else
            {
                return head;
            }
        }
        return NULL;
    }
};

//SECOND TRIAL
//unordered_map is better, and 'bool' can also take place of 'int'

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool>mp;
        while(head)
        {
            if(mp[head]==true)
                return head;
            mp[head] = true;
            head = head->next;
        }
        return NULL;
    }
};
