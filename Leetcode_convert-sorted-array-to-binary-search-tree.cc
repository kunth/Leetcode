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

//SECOND TRIAL, 60ms
class Solution {
private:
    TreeNode* construct_tree(TreeNode* root, vector<int>& num, int begin, int end)
    {
        if(begin > end)
            return NULL;
        int mid = (begin+end)/2;
        root = new TreeNode(num[mid]);
        root->left = construct_tree(root->left, num, begin, mid-1);
        root->right = construct_tree(root->right, num, mid+1, end);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return construct_tree(NULL, num, 0, num.size()-1);
    }
};
