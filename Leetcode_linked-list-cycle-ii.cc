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

//Follow up: O(1) space solution, without extra space
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
    int Cnt_link_len(ListNode* head)
    {
        int cnt = 0;
        while(head)
        {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *fast = head->next, *slow = head;
        while(fast && fast != slow)
        {
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else
                return NULL;
            slow = slow->next;
        }
        if(!fast)
            return NULL;
        fast = fast->next;
        slow->next = NULL;
        int len1 = Cnt_link_len(head);
        int len2 = Cnt_link_len(fast);
        if(len1<len2)
            swap(head, fast);
        len1 = len1>=len2 ? len1-len2 : len2-len1;
        while(len1--)
            head = head->next;
        while(head && head != fast)
        {
            head = head->next;
            fast = fast->next;
        }
        if(!head)
            return NULL;
        return head;
    }
};
