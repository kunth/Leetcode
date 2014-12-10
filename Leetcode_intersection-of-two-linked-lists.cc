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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        int la = 0, lb = 0;
        ListNode*pa = headA, *pb = headB;
        while(pa) {
            ++la;
            pa = pa->next;
        }
        while(pb) {
            ++lb;
            pb = pb->next;
        }
        pa = headA;
        pb = headB;
        if(la<lb) {
            swap(la, lb);
            swap(pa, pb);
        }
        for(int i = 0; i<la-lb; ++i)
            pa = pa->next;
        while(pa) {
            if(pa == pb)
                return pa;
            pa = pa->next;
            pb = pb->next;
        }
        return NULL;
    }
};
