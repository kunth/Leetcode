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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> st;
        vector<int>vec;
        TreeNode* p = root;
        
        while(p)
        {
        while(p)
        {
            st.push(p);
            vec.push_back(p->val);
            p = p->left;
        }
        while(!st.empty() && !(st.top()->right))
        {
            st.pop();
        }
        if(!st.empty())
        {
            p = st.top()->right;
            st.pop();
        }
        }
        return vec;
    }
};
