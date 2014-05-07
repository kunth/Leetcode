# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if not head or not head.next: return head
        p1 = h1 = head
        p2 = h2 = head.next
        while p1 and p2:
            p1.next = p2.next
            p1 = p1.next #Attention: if I change the last two sentences to p1 = p1.next = p2.next, it has runtime error. This is different from c++.
            if not p1: break
            p2.next = p1.next
            p2 = p2.next
        nxt1 = p1 = h2
        nxt2 = p2 = h1
        while p1 and p2:
            nxt1 = p1.next
            nxt2 = p2.next
            p1.next = p2
            if nxt1:
                p2.next = nxt1
            p1 = nxt1
            p2 = nxt2
        return h2



