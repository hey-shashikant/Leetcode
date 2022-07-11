1st Approach : 

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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int>result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int>v;
            for(int i=0; i<len; i++){
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            result.push_back(v.back());
        }
        return result;
    }
};

2nd Approach : 

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
        void solve(TreeNode* root, int level, vector<int> &result){
        if(root == nullptr){
            return;
        }
        if(result.size() < level){
            result.push_back(root->val);
        }
        solve(root->right,level+1,result);
        solve(root->left,level+1,result);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        solve(root,1,result);
        return result;
    }
};

Problem Link : https://leetcode.com/problems/binary-tree-right-side-view/
