# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root, ans, cnt, k):
        if root is None:
            return
        self.helper(root.left, ans, cnt, k)
        cnt[0] += 1
        if cnt[0] == k:
            ans[0] = root.val
            return
        self.helper(root.right, ans, cnt, k)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        ans, cnt = [0], [0]
        self.helper(root, ans, cnt,k)
        return ans[0]