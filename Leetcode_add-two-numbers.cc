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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<int>vec;
        int sum, carry = 0;
        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            if(sum >= 10)
            {
                vec.push_back(sum-10);
                carry = 1;
            }
            else
            {
                vec.push_back(sum);
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1)
        {
            while(l1)
            {
                sum = l1->val + carry;
                if(sum >= 10)
                {
                    vec.push_back(sum-10);
                    carry = 1;
                }
                else
                {
                    vec.push_back(sum);
                    carry = 0;
                }
                l1 = l1->next;
            }
        }
        else
        {
            while(l2)
            {
                sum = l2->val + carry;
                if(sum >= 10)
                {
                    vec.push_back(sum-10);
                    carry = 1;
                }
                else
                {
                    vec.push_back(sum);
                    carry = 0;
                }
                l2 = l2->next;
            }
        }
        if(carry)
        {
            vec.push_back(1);
        }
        ListNode* head;
        vector<ListNode*> addrvec;
        for(int i = 0; i < vec.size(); ++i)
        {
            if(i == 0)
            {
                head = new ListNode(vec[i]);
            }
            else
            {
                ListNode *p = new ListNode(vec[i]);
                addrvec.push_back(p);
            }
        }
        addrvec.push_back(NULL);
        ListNode* lp = head;
        for(int i = 0; i < vec.size(); ++i)
        {
            lp->next = addrvec[i];
            lp = addrvec[i];
        }
        return head;
    }
};
