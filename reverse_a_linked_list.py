# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr,prev,nextt = head, None, None
        while curr:
            nextt = curr.next
            curr.next = prev

            prev = curr
            curr = nextt
        
        return prev