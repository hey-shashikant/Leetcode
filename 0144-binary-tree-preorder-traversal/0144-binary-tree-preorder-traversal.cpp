/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // solving it using the iterative way using stack.
        vector<int> preOrder;
        if(root == nullptr) {
            return preOrder;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size() > 0) {
            TreeNode *top = stk.top();
            preOrder.push_back(top->val);
            stk.pop();
            if(top->right) {
                stk.push(top->right);
            }
            if(top->left){
                stk.push(top->left);
            }
        }
        return preOrder;  
    }
};