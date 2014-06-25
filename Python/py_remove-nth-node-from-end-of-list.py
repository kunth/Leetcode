# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        p1 = p2 = head
        while n and p1:
            p1 = p1.next
            n -= 1
        if not p1:
            return head.next
        else:
            while p1.next:
                p1 = p1.next;
                p2 = p2.next;
            p2.next = p2.next.next
            return head
