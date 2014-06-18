# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, root, left):
        if root.val==left and not root.left and not root.right:
            return True
        if root.left and self.dfs(root.left, left-root.val):
            return True
        if root.right and self.dfs(root.right, left-root.val):
            return True
        return False
    # @param root, a tree node
    # @param sum, an integer
    # @return a boolean
    def hasPathSum(self, root, sum):
        if not root:
            return False
        return self.dfs(root, sum)
