//http://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> >res;
        bool flag = true;
        if(!root)
        {
            return res;
        }
        else
        {
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty())
            {
                int size = q.size();
                vector<int> vec;
                while(vec.size() < size)
                {
                    TreeNode* root = q.front();
                    q.pop();
                    vec.push_back(root->val);

                    if(root->left)
                    {
                        q.push(root->left);
                    }
                    if(root->right)
                    {
                        q.push(root->right);
                    }
                }
                flag = !flag;
                if(flag)
                {
                    reverse(vec.begin(), vec.end());
                }
                res.push_back(vec);
            }
        }
        return res;
    }
};
