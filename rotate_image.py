from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        i,j = 0,len(matrix)-1
        while i < j:
            matrix[i],matrix[j] = matrix[j],matrix[i]
            i += 1
            j -= 1
        
        for i in range(len(matrix)):
            for j in range(i):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
                
                
if __name__ == "__main__":
    sol = Solution()
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    sol.rotate(matrix)
    for row in matrix:
        print(row)