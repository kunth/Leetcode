# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        if not head : return False
        h1 = h2 = head
        while True:
            h1 = h1.next
            if h2: h2 = h2.next
            else: return False
            if h2: h2 = h2.next
            else: return False
            if h1 == h2:
                return True
