from collections import deque
from typing import List

class Solution:
    def bfs(self, i, j, visited, grid):
        row,col = len(grid), len(grid[0])
        dirs = [-1,0,1,0,-1]
        qq = deque()
        qq.append((i,j))
        visited[i][j] = True

        while qq:
            pair = qq.popleft()
            r = pair[0]
            c = pair[1]
            for d in range(4):
                r1 = r + dirs[d]
                c1 = c + dirs[d+1]
                if r1 >= 0 and r1 < row and c1 >= 0 and c1 < col and grid[r1][c1] == '1' and visited[r1][c1] == False:
                    qq.append((r1,c1))
                    visited[r1][c1] = True


    def numIslands(self, grid: List[List[str]]) -> int:
        row,col = len(grid), len(grid[0])
        count = 0
        visited = [[False for _ in range(col)] for _ in range(row)]

        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1' and visited[i][j] == False:
                    self.bfs(i,j,visited,grid)
                    count += 1
            
        return count