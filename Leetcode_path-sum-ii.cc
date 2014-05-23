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
    vector<vector<int> >res;
    void dfs(TreeNode*p, vector<int>vec, int dest)
    {
        if(p->val==dest && !p->left && !p->right)
        {
            vec.push_back(p->val);
            res.push_back(vec);
            return;
        }
        if(p->left)
        {
            vec.push_back(p->val);
            dest-=p->val;
            dfs(p->left, vec, dest);
            vec.pop_back();
            dest+=p->val;
        }
        if(p->right)
        {
            vec.push_back(p->val);
            dest-=p->val;
            dfs(p->right, vec, dest);
            dest+=p->val;
            vec.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        res.clear();
        if(!root)
            return res;
        vector<int>vec;
        dfs(root, vec, sum);
        return res;
    }
};
