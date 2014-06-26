/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
vector<int> invec, postvec;
TreeNode* construct_tree(int left, int right)
{
     if(left>right || postvec.empty())
         return NULL;
     int root_val = postvec.back();
     TreeNode* p = new TreeNode(root_val);
     postvec.pop_back();
     if(left==right)
         return p;
     int root_index = 0;
     for(; root_index < invec.size(); ++root_index)
         if(invec[root_index]==root_val)
             break;
     if(root_index==left)
     {
         p->right = construct_tree(left+1, right);
     }
     else if(root_index==right)
     {
         p->left = construct_tree(left, right-1);
     }
     else
     {
         p->right = construct_tree(root_index+1, right);
         p->left = construct_tree(left, root_index-1);
     }
     return p;
}
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty())
            return NULL;
        invec = inorder;
        postvec = postorder;
        return construct_tree(0, invec.size()-1);
    }
}

//SECOND TRIAL, 116ms
class Solution {
private:
    TreeNode *construct(int in[], int post[], int len)
    {
        if(len<=0)
            return NULL;
        int root_val = post[len-1];
        TreeNode* root = new TreeNode(root_val);
        int offset = 0;
        while(offset<len && in[offset]!=root_val)
            ++offset;
        root->left = construct(in, post, offset);
        root->right = construct(in+offset+1, post+offset, len-1-offset);
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty())
            return NULL;
        int *in = &inorder[0], *post = &postorder[0];
        return construct(in, post, inorder.size());
    }
};
