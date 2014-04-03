 vector<int>prevec, invec;
 
 TreeNode* Construct(int pre_pos, int in_left, int in_right)
 {
     if(pre_pos>=prevec.size() || in_left>in_right)
     {
         return NULL;
     }
     TreeNode* p = new TreeNode(prevec[pre_pos]);
     if(in_left==in_right)
         return p;
     int i = 0;
     for(; i < invec.size(); ++i)
     {
         if(prevec[pre_pos]==invec[i])
             break;
     }
     //left tree null
     if(i == in_left)
     {
         p->right = Construct(pre_pos+1, in_left+1, in_right);
     }
     //right tree null
     else if(i==in_right)
     {
         p->left = Construct(pre_pos+1, in_left, in_right-1);
     }
     else
     {
         p->left = Construct(pre_pos+1, in_left, i-1);
         p->right = Construct(pre_pos+i-in_left+1, i+1, in_right);
     }
     return p;
 }
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty())
            return NULL;
        prevec = preorder;
        invec = inorder;
        return Construct(0, 0, preorder.size()-1);
    }
};
