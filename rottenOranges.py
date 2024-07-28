class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        fresh, cnt = 0, -1
        dirs = [-1,0,1,0,-1]
        qq = deque()
        row,col = len(grid), len(grid[0])

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 2:
                    qq.append((i,j))
                if grid[i][j] == 1:
                    fresh += 1
        
        while qq:
            size = len(qq)
            for _ in range(size):
                pair = qq.popleft()
                for i in range(4):
                    r1 = pair[0] + dirs[i]
                    c1 = pair[1] + dirs[i+1]
                    if r1 >= 0 and r1 < row and c1 >= 0 and c1 < col and grid[r1][c1] == 1:
                        fresh -= 1
                        grid[r1][c1] = 2
                        qq.append((r1,c1))
            cnt += 1
        
        if fresh > 0:
            return -1
        if cnt == -1:
            return 0
        return cnt