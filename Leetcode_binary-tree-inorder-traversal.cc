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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int>res;
        if(root)
        {
            stack<TreeNode*>s;
            s.push(root);
            while(!s.empty())
            {
                while(root->left)
                {
                    root = root->left;
                    s.push(root);
                }
                root = s.top();
                res.push_back(root->val);
                if(root->right)
                {
                    root = root->right;
                    s.pop();
                    s.push(root);
                }
                else
                {
                    s.pop();
                    while(!s.empty() && !s.top()->right)
                    {
                        res.push_back(s.top()->val);
                        s.pop();
                    }
                    if(!s.empty())
                    {
                        res.push_back(s.top()->val);
                        root = s.top()->right;
                        s.pop();
                        s.push(root);
                    }
                }
            }
        }
        return res;
    }
};

//SECOND TRIAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode *p = root;
        while(p)
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            if(!st.empty())
            {
                while(!st.empty() && !st.top()->right)
                {
                    ans.push_back(st.top()->val);
                    st.pop();
                }
                if(st.empty())
                    break;

                p = st.top();
                ans.push_back(p->val);
                st.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
