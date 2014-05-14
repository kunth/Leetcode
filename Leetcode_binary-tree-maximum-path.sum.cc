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
private:
    int ans;
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = root->val + max(left, 0) + max(right, 0);
        ans = max(ans, sum);
        return max(max(left, right), 0) + root->val;
    }
public:
    int maxPathSum(TreeNode *root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};
