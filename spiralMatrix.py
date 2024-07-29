class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        row,col = len(matrix), len(matrix[0])
        left,right,top,bottom = 0,col-1,0,row-1

        cnt = 0
        while left <= right and top <= bottom:
            if cnt == 0:
                for i in range(left,right+1):
                    res.append(matrix[top][i])
                top += 1
            elif cnt == 1:
                for i in range(top, bottom+1):
                    res.append(matrix[i][right])
                right -= 1
            elif cnt == 2:
                for i in range(right, left-1,-1):
                    res.append(matrix[bottom][i])
                bottom -= 1
            else:
                for i in range(bottom, top-1,-1):
                    res.append(matrix[i][left])
                left += 1
            cnt += 1
            cnt = cnt % 4
        return res