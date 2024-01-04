/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        
        // Iterative way to perform Preorder Traversal on Binary Tree using Stack.

        List<Integer>preOrder = new ArrayList<>();

        // check if root is null.

        if(root == null) {
            return preOrder;
        }
        
        Stack<TreeNode>stk = new Stack<>();
        stk.push(root);
        while(!stk.isEmpty()) {
            TreeNode top = stk.peek();
            stk.pop();
            preOrder.add(top.val);
            if(top.right != null) {
                stk.push(top.right);
            }
            if(top.left != null) {
                stk.push(top.left);
            }
        }
        return preOrder;
    }
}