# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        if not root:
            return 0
        q = [root]
        ans = 0
        while q:
            sz = len(q)
            ans += 1
            while sz:
                sz-=1
                cur = q.pop()
                if cur.left:
                    q.insert(0, cur.left)
                if cur.right:
                    q.insert(0, cur.right)
        return ans
