class Solution {
public:
    void dfs(unordered_map<string, set<string>> &graph, string email, unordered_set<string> &visited, vector<string> &list) {
        list.push_back(email);
        visited.insert(email);
        for (const auto& next : graph[email]) {
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                dfs(graph, next, visited, list);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, set<string>> graph;  // <email node, neighbour node>
        unordered_map<string, string> name;       // <email, name>

        // build the graph...
        for (auto& account : accounts) {
            string userName = account[0];
            for (int i = 1; i < account.size(); i++) {
                if (graph.find(account[i]) == graph.end()) {
                    graph[account[i]] = set<string>();
                }
                name[account[i]] = userName;

                if (i == 1) {
                    continue;
                }
                graph[account[i]].insert(account[i-1]);
                graph[account[i-1]].insert(account[i]);
            }
        }


        unordered_set<string> visited;
        vector<vector<string>> res;
        // search the graph..
        for (auto& kv : name) {
            string email = kv.first;
            if (visited.find(email) == visited.end()) {
                vector<string> list;
                dfs(graph, email, visited, list);
                sort(list.begin(), list.end());
                list.insert(list.begin(), kv.second);
                res.push_back(list);
            }
        }

        return res;
    }
};