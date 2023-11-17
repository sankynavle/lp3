#include <iostream>

const int MAX = 10; // You can adjust this based on your requirements

void printBoard(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    // Check for queens in the same row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int board[MAX][MAX], int col, int n) {
    if (col == n) {
        printBoard(board, n);
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; ++i) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            res = solveNQueensUtil(board, col + 1, n) || res;

            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

void solveNQueens(int n, int firstQueenRow) {
    int board[MAX][MAX] = {0};

    // Place the first queen
    board[firstQueenRow][0] = 1;

    if (!solveNQueensUtil(board, 1, n)) {
        std::cout << "Solution does not exist.\n";
    }
}

int main() {
    int n, firstQueenRow;

    std::cout << "Enter the size of the chessboard (n): ";
    std::cin >> n;

    std::cout << "Enter the row for the first queen (0 to " << n - 1 << "): ";
    std::cin >> firstQueenRow;

    if (firstQueenRow < 0 || firstQueenRow >= n) {
        std::cout << "Invalid row for the first queen.\n";
        return 1;
    }

    std::cout << "Possible solutions for N-Queens:\n";
    solveNQueens(n, firstQueenRow);

    return 0;
}

/*
Time Complexity: O(N!)
Auxiliary Space: O(N^2)
*/

