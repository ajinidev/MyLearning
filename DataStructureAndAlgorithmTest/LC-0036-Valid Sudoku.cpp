#include "pch.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Sudoku {
public:
    bool isValidSudoku(vector<vector<char>> board) {
        for (auto i = 0; i < 9; i++) {
            unordered_map<char, int> row;
            for (auto j = 0; j < 9; j++) {
                auto var = board[i][j];
                if (var != '.') {
                    row[var]++;
                    if (row[var] > 1) {
                        return false;
                    }
                }
            }
            unordered_map<char, int> col;
            for (auto j = 0; j < 9; j++) {
                auto var = board[j][i];
                if (var != '.') {
                    col[var] = col[var] + 1;
                    if (col[var] > 1) {
                        return false;
                    }
                }
            }
            unordered_map<char, int> cell;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int r = ((i % 3) * 3) + j;
                    int c = ((i / 3) * 3) + k;
                    auto var = board[r][c];
                    if (var != '.') {
                        cell[var] = cell[var] + 1;
                        if (cell[var] > 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};


TEST(SudokuTest, TC0) {
    Sudoku tester;
    vector<vector<char>> board = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };
    EXPECT_EQ(true, tester.isValidSudoku(board));
}


TEST(SudokuTest, TC1) {
    Sudoku tester;
    vector<vector<char>> board = {
        { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };
    EXPECT_EQ(false, tester.isValidSudoku(board));
}