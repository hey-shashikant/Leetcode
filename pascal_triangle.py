class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1],[1,1]]
        else:
            triangle = []
            triangle.append([1])
            triangle.append([1,1])
            for i in range(2,numRows):
                temp = []
                temp.append(1)
                for j in range(1,i):
                    temp.append(triangle[i-1][j-1] + triangle[i-1][j])
                temp.append(1)
                triangle.append(temp)
            
            return triangle