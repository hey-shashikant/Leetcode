class Solution {
public:
    // Directional offsets for navigating neighboring cells
    vector<int> dirs = {-1, 0, 1, 0, -1};

    // Helper function to perform BFS traversal from a given cell
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            // Explore all four directions
            for (int i = 0; i < 4; i++) {
                int newRow = current.first + dirs[i];
                int newCol = current.second + dirs[i + 1];

                // Check if the new cell is within bounds and is unvisited land
                if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() &&
                    grid[newRow][newCol] == '1' && visited[newRow][newCol] == 0) {
                    // Mark the cell as visited and add it to the queue for further exploration
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    // Function to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0)); // Initialize visited array

        int islandCount = 0; // Counter for the number of islands

        // Iterate through each cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If the cell represents unvisited land, perform BFS traversal from that cell
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    bfs(i, j, grid, visited);
                    islandCount++; // Increment island count after exploring all connected land cells
                }
            }
        }

        return islandCount;
    }
};