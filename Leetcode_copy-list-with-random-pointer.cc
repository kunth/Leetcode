//http://oj.leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> dm;
        RandomListNode* p = head, *lastp = NULL, *newhead = NULL;
        while(p)
        {
            RandomListNode* pnew = new RandomListNode(p->label);
            dm.insert(pair<RandomListNode*, RandomListNode*>(p, pnew));
            if(p!=head)
            {
                lastp->next=pnew;
                lastp = lastp->next;
            }
            else
            {
                newhead = lastp = pnew;
            }
            p = p->next;
        }
        p = head;
        while(p)
        {
            dm[p]->random = dm[p->random];
            p = p->next;
        }
        return newhead;
    }
};
