/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
    void construct_tree(TreeNode**p, vector<int>vec)
    {
        if(vec.empty())
            return;
        int mid = vec.size()/2;
        *p = new TreeNode(vec[mid]);
        vector<int>left_vec, right_vec;
        for(int i=0; i<mid; ++i)
            left_vec.push_back(vec[i]);
        for(int i=mid+1; i<vec.size(); ++i)
            right_vec.push_back(vec[i]);
        construct_tree(&((*p)->left), left_vec);
        construct_tree(&((*p)->right), right_vec);
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)
            return NULL;
        vector<int>vec;
        while(head)
        {
            vec.push_back(head->val);
            head=head->next;
        }
        TreeNode* tree_head = NULL;
        construct_tree(&tree_head, vec);
        return tree_head;
    }
};
