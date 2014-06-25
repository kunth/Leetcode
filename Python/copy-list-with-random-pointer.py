# Definition for singly-linked list with a random pointer.
# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if not head:
            return head;
        mp = {}
        p = head
        pre = None
        while p:
            q = RandomListNode(p.label)
            mp[p] = q
            if pre:
                pre.next = q
            pre = q
            p = p.next
        p = head
        while p:
            if p.random:
                mp[p].random = mp[p.random]
            else:
                mp[p].random = None
            p = p.next
        return mp[head]
