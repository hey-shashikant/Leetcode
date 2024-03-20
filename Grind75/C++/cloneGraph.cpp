/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copies;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* newNode = new Node(node->val, {});
        copies[node] = newNode;
        if (node == NULL) return newNode;
        queue<Node*> qq;
        qq.push(node);
        while(!qq.empty()) {
            Node* curr = qq.front();
            qq.pop();
            for (Node* neighbor : curr->neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor->val, {});
                    qq.push(neighbor);
                } 
                copies[curr] -> neighbors.push_back(copies[neighbor]);

            }
        }
        return newNode;
    }
};