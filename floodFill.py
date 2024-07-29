class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        row,col = len(image), len(image[0])
        initialColor = image[sr][sc]
        dirs = [-1,0,1,0,-1]
        if image[sr][sc] == color:
            return image
        qq = deque()
        qq.append((sr,sc))
        image[sr][sc] = color
        while qq:
            r,c = qq.popleft()
            for i in range(4):
                r1 = r + dirs[i]
                c1 = c + dirs[i+1]

                if r1 >= 0 and r1 < row and c1 >= 0 and c1 < col and image[r1][c1] == initialColor:
                    image[r1][c1] = color
                    qq.append((r1,c1))
        
        return image