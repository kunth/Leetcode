# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        res = []
        if not root:
            return res
        q = [root]
        while q:
            sz = len(q)
            level = []
            while sz:
                sz -= 1
                cur = q.pop()
                level.append(cur.val)
                if cur.left:
                    q.insert(0, cur.left)
                if cur.right:
                    q.insert(0, cur.right)
 
            res.append(level)
        return res
