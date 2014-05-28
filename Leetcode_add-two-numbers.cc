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


//SECOND TRIAL
class Solution {
public:
    int cnt_list_node(ListNode* head)
    {
        int cnt = 0;
        while(head)
        {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int v = 0, carry = 0;
        int c1 = cnt_list_node(l1);
        int c2 = cnt_list_node(l2);
        if(c1 < c2)
            swap(l1, l2);
        ListNode*p = l1, *pre = NULL;
        while(l2)
        {
            pre = p;
            v = p->val + l2->val + carry;
            carry = v / 10;
            v %= 10;
            p->val = v;
            p = p->next;
            l2 = l2->next;
        }
        while(carry)
        {
            if(p)
            {
                pre = p;
                v = p->val + carry;
                carry = v/10;
                v %= 10;
                p->val = v;
                p = p->next;
            }
            else
            {
                ListNode* nd = new ListNode(carry);
                pre->next = nd;
                return l1;
            }
        }
        return l1;
    }
};
