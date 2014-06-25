# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = -10000000  # since -sys.maxint could not be used in leetcode oj
    def dfs(self, root):
        if not root:
            return 0
        lval = self.dfs(root.left)
        rval = self.dfs(root.right)
        self.ans = max(self.ans, root.val + max(0, lval) + max(0, rval))
        return root.val + max(0, max(lval, rval))
    # @param root, a tree node
    # @return an integer
    def maxPathSum(self, root):
        if not root:
            return 0;
        self.dfs(root)
        return self.ans
