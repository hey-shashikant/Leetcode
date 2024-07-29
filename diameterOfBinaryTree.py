# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def height(self, root):
        if root is None:
            return 0
        return 1 + max(self.height(root.left), self.height(root.right))

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        leftHeight = self.height(root.left)
        rightHeight = self.height(root.right)

        return max(leftHeight + rightHeight, max(self.diameterOfBinaryTree(root.left), self.diameterOfBinaryTree(root.right)))