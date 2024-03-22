class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int>dir = {-1,0,1,0,-1};
        queue<pair<int,int>>q;
        int fresh = 0, row = grid.size(), col = grid[0].size(), res = -1;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh+=1;
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int>t = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int r = t.first + dir[i];
                    int c = t.second + dir[i+1];
                    if((r >= 0 and r < row) and (c >= 0 and c < col) and grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
            res++;
        }
        if(fresh > 0){
            return -1;
        }
        if(res == -1){
            return 0;
        }
        return res;
    }
};