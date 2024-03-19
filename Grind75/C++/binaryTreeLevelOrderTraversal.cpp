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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        queue<TreeNode*>qq;
        qq.push(root);
        while(!qq.empty()) {
            int count = qq.size();
            vector<int>tmp;
            for (int i = 0; i < count; i++) {
                TreeNode *temp = qq.front();
                qq.pop();
                if (temp->left != NULL) qq.push(temp->left);
                if (temp->right) qq.push(temp->right);
                tmp.push_back(temp->val);   
            }
            res.push_back(tmp);
        }
        return res;
    }
};