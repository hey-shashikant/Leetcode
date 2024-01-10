class Solution {
    public int orangesRotting(int[][] grid) {
        int[] dirs = {-1,0,1,0,-1};
        Queue<int[]> queue = new LinkedList<>();
        int freshOranges = 0, minutes = -1;
        for(int i = 0; i < grid.length; i += 1) {
            for(int j = 0; j < grid[i].length; j += 1) {
                if(grid[i][j] == 2) {
                    queue.offer(new int[] {i,j});
                } 
                if(grid[i][j] == 1) {
                    freshOranges += 1;
                }
            }
        }
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i = 0; i < size; i += 1) {
                int[] temp = queue.poll();
                for(int j = 0; j < 4; j += 1) {
                    int x = temp[0] + dirs[j];
                    int y = temp[1] + dirs[j+1];
                    if(x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        freshOranges -= 1;
                        queue.offer(new int[] {x,y});
                    }
                }
            }
            minutes += 1;
        }
        if(freshOranges > 0) {
            return -1;
        } else if(minutes == -1) {
            return 0;
        }
        return minutes;
    }
}