# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        if not root: return
        s={0: [root]}
        cur = 0
        while 1:
            if not s.has_key(cur):
                break
            li = s[cur]
            for i in li:
                if i.left:
                    if s.has_key(cur+1):
                        s[cur+1][-1].next = i.left
                        s[cur+1].append(i.left)
                    else:
                        s[cur+1] = [i.left]
                if i.right:
                    if s.has_key(cur+1):
                        s[cur+1][-1].next = i.right
                        s[cur+1].append(i.right)
                    else:
                        s[cur+1] = [i.right]
            cur += 1
        return
        
