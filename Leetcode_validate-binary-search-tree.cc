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
    void inorder(TreeNode*p, vector<int>&vec)
    {
        if(p->left)
            inorder(p->left, vec);
        vec.push_back(p->val);
        if(p->right)
            inorder(p->right, vec);
    }
    bool isValidBST(TreeNode *root) {
        if(!root)
            return true;
        vector<int>vec;
        inorder(root, vec);
        bool ans = true;
        for(int i = 0; i<vec.size()-1; ++i)
        {
            if(vec[i]>=vec[i+1])
            {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
