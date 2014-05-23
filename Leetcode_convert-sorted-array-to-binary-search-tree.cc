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
        for(int i = 0; i<mid; ++i)
            left_vec.push_back(vec[i]);
        for(int i=mid+1; i<vec.size(); ++i)
            right_vec.push_back(vec[i]);
        construct_tree(&((*p)->left), left_vec);
        construct_tree(&((*p)->right), right_vec);
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.empty())
            return NULL;
        TreeNode* head = NULL;
        construct_tree(&head, num);
        return head;
    }
};
