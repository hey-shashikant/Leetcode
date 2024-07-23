from typing import List
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        row,col = len(matrix), len(matrix[0])
        min_row = [min(row) for row in matrix]
        max_col = [max(col) for col in zip(*matrix)]

        lucky_number = [matrix[i][j] for i in range(row) for j in range(col) if matrix[i][j] == min_row[i] and matrix[i][j] == max_col[j]]

        return lucky_number

solution = Solution()
matrix = []
row = int(input())
for _ in range(row):
    row = list(map(int,input().split()))
    matrix.append(row)
lucky_number = solution.luckyNumbers(matrix)
print(lucky_number)