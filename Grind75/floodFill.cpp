class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color) {
            return image;
        }

        queue<pair<int,int>> pq;
        pq.push({sr,sc});

        while(!pq.empty()) {
            int r = pq.front().first;
            int c = pq.front().second;
            pq.pop();

            image[r][c] = color;

            vector<pair<int,int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}}; 

            for (const auto& dir : dirs) {
                int row = r + dir.first;
                int col = c + dir.second;
                if (row >= 0 && row < image.size() && col >= 0 && col < image[0].size() && image[row][col] == oldColor) {
                    pq.push({row,col});
                }
            }
        }
        return image;
    }
};