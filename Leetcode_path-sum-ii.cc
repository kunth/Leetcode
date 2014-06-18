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

//SECOND TRIAL
class Solution {
private:
    vector<vector<int> >ans;
    void dfs(vector<int>&path, TreeNode* root, int sum)
    {
        if(sum==root->val && !root->left && !root->right)
        {
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        if(root->left)
            dfs(path, root->left, sum-root->val);
        if(root->right)
            dfs(path, root->right, sum-root->val);
        path.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(!root)
            return ans;
        vector<int>path;
        dfs(path, root, sum);
        return ans;
    }
};
