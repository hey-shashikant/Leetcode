class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // Get the dimensions of the matrix
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Define directions for adjacent cells (up, down, left, right)
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        // Create a queue to store the coordinates of cells with '0' value
        queue<pair<int, int>> zeroQueue;
        
        // Iterate through the matrix to find cells with value '0' and mark others as '-1'
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    zeroQueue.push({r, c});
                } else {
                    matrix[r][c] = -1;
                }
            }
        }
        
        // Perform BFS traversal starting from cells with value '0'
        while (!zeroQueue.empty()) {
            auto [row, col] = zeroQueue.front();
            zeroQueue.pop();
            
            // Check adjacent cells
            for (int i = 0; i < 4; i++) {
                int newRow = row + dirs[i];
                int newCol = col + dirs[i + 1];
                
                // Check if the adjacent cell is within the bounds and not visited yet
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] == -1) {
                    // Update the distance value and add the cell to the queue
                    matrix[newRow][newCol] = matrix[row][col] + 1;
                    zeroQueue.push({newRow, newCol});
                }
            }
        }
        return matrix;
    }
};