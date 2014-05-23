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
    vector<TreeNode*> vec;
    void pretraverse(TreeNode*p)
    {
        if(p)
        {
            vec.push_back(p);
            pretraverse(p->left);
            pretraverse(p->right);
        }
        return;
    }
    void flatten(TreeNode *root) {
        if(root)
        {
            vec.clear();
            pretraverse(root);
            TreeNode* p = root;
            p->left = NULL;
            for(int i = 1; i < vec.size(); ++i)
            {
                p->right = vec[i];
                p->left = NULL;
                p = p->right;
            }
        }
    }
};
