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
    void dfs(TreeNode*p, int& allsum, int pathsum)
    {
        pathsum = pathsum*10+p->val;
        if(!p->left && !p->right)
        {
            allsum+=pathsum;
            return;
        }
        if(p->left)
        {
            dfs(p->left, allsum, pathsum);
        }
        if(p->right)
        {
            dfs(p->right, allsum, pathsum);
        }
    }
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        int ret = 0, pathsum = 0;
        dfs(root, ret, pathsum);
        return ret;
    }
};

//SECOND TRIAL, the first one is better, obviously.
class Solution {
private:
    void dfs(int&ans, vector<int>&vec, TreeNode*root)
    {
        if(!root->left && !root->right)
        {
            int sum = 0, ratio = 1;
            for(int i = vec.size()-1; i>=0; --i)
            {
                sum += ratio * vec[i];
                ratio *= 10;
            }
            ans += sum;
            return;
        }
        if(root->left)
        {
            vec.push_back(root->left->val);
            dfs(ans, vec, root->left);
            vec.pop_back();
            
        }
        if(root->right)
        {
            vec.push_back(root->right->val);
            dfs(ans, vec, root->right);
            vec.pop_back();
        }
    }
public:
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        int ans = 0;
        vector<int>vec;
        vec.push_back(root->val);
        dfs(ans, vec, root);
        return ans;
    }
};
