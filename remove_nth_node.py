# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None or head.next is None:
            return None
        slow,fast = head,head
        while n > 0:
            fast = fast.next
            n -= 1
        
        if not fast:
            return head.next
        
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next
            
        slow.next = slow.next.next
        return head