/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if(!head || !head->next)
      return head;
    ListNode*p1 = head, *p2 = head, *ph = NULL;
    while(p1)
    {
      p1 = p1->next;
      if(p1)
        p1 = p1->next;
      ph = p2;
      p2 = p2->next;
    }
    ph->next = NULL;
    head = sortList(head);
    p2 = sortList(p2);
    ListNode*pans = NULL;
    ListNode**ppcur = &pans;
    while(head && p2)
    {
      if(head->val < p2->val)
      {
        *ppcur = head;
        head = head->next;
      }
      else
      {
        *ppcur = p2;
        p2 = p2->next;
      }
      ppcur = &((*ppcur)->next);
    }
    if(head)
      *ppcur = head;
    else if(p2)
      *ppcur = p2;
    return pans;
  }
};

//Solution Two
class Solution {
private:
    ListNode* merge(ListNode*l1, ListNode*l2) {
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        ListNode*head = NULL, *p1 = l1, *p2 = l2, *cur = NULL;
        while(p1 && p2) {
            if(p1->val <= p2->val) {
                if(!head)
                    head = cur = p1;
                else
                    cur = cur->next = p1;
                p1 = p1->next;
            } else {
                if(!head)
                    head = cur = p2;
                else
                    cur = cur->next = p2;
                p2 = p2->next;
            }
        }
        if(p1)
            cur->next = p1;
        else
            cur->next = p2;
        return head;
    }
    void split(ListNode*head, ListNode**l1, ListNode**l2) {
        ListNode* lnode = *l1, *rnode = *l2;
        if(!head)
            lnode = rnode = NULL;
        else if(!head->next) {
            lnode = head;
            rnode = NULL;
        } else {
            lnode = rnode = head;
            ListNode *tmp = NULL;
            while(lnode) {
                lnode = lnode->next;
                if(lnode) {
                    lnode = lnode->next;
                    tmp = rnode;
                    rnode = rnode->next;
                }
            }
            tmp->next = NULL;
            *l1 = lnode = head;
            *l2 = rnode;
        }
    }
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next)
            return head;
        ListNode*l1 = NULL, *l2 = NULL;
        split(head, &l1, &l2);
        l1 = sortList(l1);
        l2 = sortList(l2);
        return merge(l1, l2);
    }
};
