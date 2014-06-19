# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def zigzagLevelOrder(self, root):
        if not root:
            return [];
        ans = []
        q = [root]
        flag = True
        while q:
            sz = len(q)
            level = []
            while sz:
                sz -= 1
                cur = q.pop()
                if cur.left:
                    q.insert(0, cur.left)
                if cur.right:
                    q.insert(0, cur.right)
                level.append(cur.val)
            if flag:
                ans.append(level)
            else:
                ans.append(level[::-1])
            flag = not flag
        return ans
