class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        dirs = [-1,0,1,0,-1]
        fresh, count, minutes = 0,-1,0
        row,col = len(grid), len(grid[0])

        qq = deque()
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 2:
                   qq.append((i,j)) 
                if grid[i][j] == 1:
                    fresh += 1
        
        while qq:
            size = len(qq)
            for _ in range(size):
                r,c = qq.popleft()
                for i in range(4):
                    r1 = r + dirs[i]
                    c1 = c + dirs[i+1]
                    if r1 >= 0 and r1 < row and c1 >= 0 and c1 < col and grid[r1][c1] == 1:
                        grid[r1][c1] = 2
                        fresh -= 1
                        qq.append((r1,c1))
            count += 1
        
        if fresh != 0:
            return -1
        if count == -1:
            return 0
        if fresh == 0:
            return count