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

//SECOND TRIAL
class Solution {
private:
    vector<int>vec;
    void InOrder(TreeNode *root)
    {
        if(!root)
            return;
        InOrder(root->left);
        vec.push_back(root->val);
        InOrder(root->right);
    }
public:
    bool isValidBST(TreeNode *root) {
        InOrder(root);
        for(int i = 0; i<(int)vec.size()-1; ++i)
            if(vec[i] >= vec[i+1])
                return false;
        return true;
    }
};

//THIRD TRIAL
class Solution {
private:
    bool isValid(TreeNode *root, int left, int right)
    {
        if(!root)
            return true;
        if(left < root->val && root->val < right)
            return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
        else
            return false;
    }
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};
