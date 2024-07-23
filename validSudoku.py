from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        for row in board:
            row_set = set()
            for char in row:
                if char != '.':
                    if char in row_set:
                        return False
                    row_set.add(char)
        
        for col in range(9):
            col_set = set()
            for row in range(9):
                if board[row][col] != '.':
                    if board[row][col] in col_set:
                        return False
                    col_set.add(board[row][col])
        
        for row in range(0,9,3):
            for col in range(0,9,3):
                matrix_set = set()
                for i in range(row,row+3):
                    for j in range(col,col+3):
                        if board[i][j] != '.':
                            if board[i][j] in matrix_set:
                                return False
                            matrix_set.add(board[i][j])
        
        return True
                
if __name__ == "__main__":
    sol = Solution()
    board = [
        ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
        ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
        ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
        ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
        ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
        ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
        ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
        ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
        ['.', '.', '.', '.', '8', '.', '.', '7', '9']
    ]

    print("Valid" if sol.isValidSudoku(board) else "Invalid")       
            