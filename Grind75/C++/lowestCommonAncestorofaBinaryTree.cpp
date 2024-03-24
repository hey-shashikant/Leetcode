/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or either of the nodes is found, return root
        if (!root || root == p || root == q) {
            return root;
        } 

        // Recursively search for nodes in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If one of the nodes is found in the left subtree and the other in the right subtree,
        // then the current root is the lowest common ancestor
        if (left && right) {
            return root;
        } 

        // If both nodes are in the left subtree, return the result from the left subtree
        // Otherwise, return the result from the right subtree
        return left ? left : right;
    }
};