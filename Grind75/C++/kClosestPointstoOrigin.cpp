class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            pq.push({x*x + y*x, x, y});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            vector<int> tmp = pq.top();
            res.push_back({tmp[1], tmp[2]});
            pq.pop();
        }
        return res;
        
    }
};