/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//writing this code long time ago, and it seems to be coarse
 bool cmp(const ListNode * lhs, const ListNode * rhs)
 {
    return lhs->val < rhs->val;
 }
    
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
        {
            return NULL;
        }
        vector<ListNode*>vec;
        for(int i = 0; i < lists.size(); ++i)
        {
            ListNode* pf = lists[i];
            while(pf)
            {
                vec.push_back(pf);
                pf = pf->next;
            }
        }
        sort(vec.begin(), vec.end(), cmp);
        if(!vec.empty())
        {
            ListNode* head = vec[0], *p = vec[0];
            for(int i = 0; i < vec.size(); ++i)
            {
                p->next = vec[i];
                p = p->next;
            }
            p->next = NULL;
            return head;
        }
        return NULL;
    }
};
