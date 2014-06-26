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
    vector<TreeNode*> subtree(int left, int right)
    {
        vector<TreeNode*>ans; 
        if(left > right)
        {
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i = left; i<=right; ++i)
        {
            vector<TreeNode*>left_tree = subtree(left, i-1);
            vector<TreeNode*>right_tree = subtree(i+1, right);
            for(int j = 0; j<left_tree.size(); ++j)
            {
                for(int k = 0; k<right_tree.size(); ++k)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_tree[j];
                    root->right = right_tree[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n) {
        return subtree(1, n);
    }
};
