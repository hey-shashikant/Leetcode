# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, inorder, root):
        if root is None:
            return
        self.helper(inorder, root.left);
        inorder.append(root.val)
        self.helper(inorder, root.right)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        inorder = []
        self.helper(inorder, root)
        return inorder[k-1]