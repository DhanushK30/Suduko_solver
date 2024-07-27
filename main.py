import numpy as np

def is_possible(grid, row, col, num):
    # Check if 'num' is possible at the given position (row, col) in the grid

    # Check row
    for i in range(9):
        if grid[row][i] == num:
            return False

    # Check column
    for i in range(9):
        if grid[i][col] == num:
            return False

    # Check 3x3 square
    start_row = (row // 3) * 3
    start_col = (col // 3) * 3
    for i in range(3):
        for j in range(3):
            if grid[start_row + i][start_col + j] == num:
                return False

    return True

def solve_sudoku(grid):
    # Solve the Sudoku puzzle using backtracking

    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:  # Check for empty cell
                for num in range(1, 10):
                    if is_possible(grid, row, col, num):
                        grid[row][col] = num  # Place the number in the empty cell

                        if solve_sudoku(grid):  # Recursively solve the remaining grid
                            return True

                        grid[row][col] = 0  # Backtrack if the solution is not valid

                return False

    return True  # Puzzle solved

def print_sudoku(grid):
    # Print the Sudoku grid in a visually appealing format

    for i in range(9):
        if i % 3 == 0 and i != 0:
            print("---------------------")

        for j in range(9):
            if j % 3 == 0 and j != 0:
                print("|", end=" ")
            
            if j == 8:
                print(grid[i][j])
            else:
                print(grid[i][j], end=" ")

# Get user input for the Sudoku grid
print("Enter the Sudoku grid (9 rows, each row containing 9 digits, use 0 for empty cells):")
grid = []
for _ in range(9):
    row = list(map(int, input().split()))
    grid.append(row)

solve_sudoku(grid)
print_sudoku(grid)
