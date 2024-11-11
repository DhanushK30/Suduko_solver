#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<vector<int>>& grid, int row, int col, int num) {
    // Check if 'num' is possible at the given position (row, col) in the grid

    // Check row
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; ++i) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 square
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& grid) {
    // Solve the Sudoku puzzle using backtracking

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) { // Check for empty cell
                for (int num = 1; num <= 9; ++num) {
                    if (isPossible(grid, row, col, num)) {
                        grid[row][col] = num; // Place the number in the empty cell

                        if (solveSudoku(grid)) { // Recursively solve the remaining grid
                            return true;
                        }

                        grid[row][col] = 0; // Backtrack if the solution is not valid
                    }
                }

                return false;
            }
        }
    }

    return true; // Puzzle solved
}

void printSudoku(const vector<vector<int>>& grid) {
    // Print the Sudoku grid in a visually appealing format

    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl;
        }

        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }

            if (j == 8) {
                cout << grid[i][j] << endl;
            } else {
                cout << grid[i][j] << " ";
            }
        }
    }
}

int main() {
    // Get user input for the Sudoku grid
    cout << "Enter the Sudoku grid (9 rows, each row containing 9 digits, use 0 for empty cells):" << endl;
    vector<vector<int>> grid(9, vector<int>(9));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        printSudoku(grid);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
