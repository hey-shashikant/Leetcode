# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow,fast = head,head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
        
        newHead = slow
        prevv,nextt = None,None
        while newHead is not None:
            nextt = newHead.next
            newHead.next = prevv
            
            prevv = newHead
            newHead = nextt
            
        while head is not None and prevv is not None:
            if head.val != prevv.val:
                return False
            head = head.next
            prevv = prevv.next
        return True
        
        