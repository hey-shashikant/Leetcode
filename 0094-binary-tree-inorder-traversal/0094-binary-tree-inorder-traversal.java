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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer>inOrder = new ArrayList<>();
        if(root == null) {
            return inOrder;
        }
        Stack<TreeNode>stk = new Stack<>();
        while(!stk.isEmpty() || root != null) {
            if(root != null) {
                stk.push(root);
                root = root.left;
            } else {
                TreeNode top = stk.peek();
                stk.pop();
                inOrder.add(top.val);
                root = top.right;
            }
        }
        return inOrder;
    }
}