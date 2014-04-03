class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int>ans;
        if(!root)
            return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            if(st.top()->left != root)
            {
                while(root->left)
                {
                    root = root->left;
                    st.push(root);
                }
            }
            else
            {
                root = st.top();
            }
            if(root->right)
            {
                root = root->right;
                st.push(root);
            }
            //deal with leaf node
            else
            {
                ans.push_back(root->val);
                st.pop();
                if(!st.empty() && st.top()->right==root)
                {
                    while(!st.empty() && st.top()->right==root)
                    {
                        root = st.top();
                        st.pop();
                        ans.push_back(root->val);
                    }
                }
                if(!st.empty() && st.top()->left==root)
                {
                    while(!st.empty() && st.top()->left==root && !st.top()->right)
                    {
                        root = st.top();
                        st.pop();
                        ans.push_back(root->val);
                    }
                    if(!st.empty() && st.top()->right == root)
                    {
                        while(!st.empty() && st.top()->right==root)
                        {
                            root = st.top();
                            st.pop();
                            ans.push_back(root->val);
                        }
                        //ans.push_back(root->val);
                    }
                    else if(!st.empty() && st.top()->right)
                    {
                        root = st.top()->right;
                        st.push(root);
                    }
                }
            }
        }
        return ans;
    }
};
