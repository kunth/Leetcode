# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def minDepth(self, root):
        if not root:
            return 0
        depth = 0
        q = [root]
        while q:
            depth += 1
            sz = len(q)
            while sz:
                sz -= 1
                cur = q.pop()
                if not cur.left and not cur.right:
                    return depth
                if cur.left:
                    q.insert(0, cur.left)
                if cur.right:
                    q.insert(0, cur.right)
