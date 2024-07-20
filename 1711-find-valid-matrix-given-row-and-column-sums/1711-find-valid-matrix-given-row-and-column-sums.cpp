class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size(), col = colSum.size();
        vector<vector<int>> resultMatrix(row, vector<int>(col,0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int mini = min(rowSum[i], colSum[j]);
                rowSum[i] -= mini;
                colSum[j] -= mini;
                resultMatrix[i][j] = mini;
            }
        }
        return resultMatrix;
    }
};