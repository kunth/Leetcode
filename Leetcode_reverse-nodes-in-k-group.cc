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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head)
            return NULL;
        if(k<=1)
            return head;
        vector<ListNode*> vec;
        ListNode* p = head, *newHead=NULL, *q=NULL;
        while(p)
        {
            while(p && vec.size()<k)
            {
                vec.push_back(p);
                p = p->next;
            }
            if(vec.size()==k)
            {
                if(!newHead)
                {
                    q = newHead = vec.back();
                    vec.pop_back();
                }
                while(!vec.empty())
                {
                    q->next = vec.back();
                    vec.pop_back();
                    q = q->next;
                }
            }
            else
            {
                if(!newHead)
                {
                    return head;
                }
                else
                {
                    for(int i = 0; i < vec.size(); ++i)
                    {
                        q->next = vec[i];
                        q = q->next;
                    }
                }
            }
        }
        q->next = NULL;
        return newHead;
    }
};
