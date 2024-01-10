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
    unordered_map<int,vector<int>> graph;
    void createGraph(TreeNode *root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,-1});
        while(q.size()) {
            auto [node,parent] = q.front();
            q.pop();
            if(parent != -1) {
                graph[parent].push_back(node->val);
                graph[node->val].push_back(parent);
            }
            if(node->left != nullptr)
                q.push({node->left,node->val});
            if(node->right != nullptr)
                q.push({node->right,node->val});
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        createGraph(root);
        
        unordered_map<int,bool>seen;
        queue<int>q;
        q.push(start);
        seen[start] = true;
        int time = 0;
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                int top = q.front();
                q.pop();
                for(auto i : graph[top]) {
                    if(seen[i] == false) {
                        seen[i] = true;
                        q.push(i);
                    }
                }
            }
            time += 1;
        }
        return time-1;
    }
};