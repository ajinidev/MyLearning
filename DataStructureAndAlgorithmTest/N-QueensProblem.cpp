#include "pch.h"
#include <string>
#include <vector>
using namespace std;


class NQueensProblem {

    bool** chessTable;
    int queensCount;

public:
    NQueensProblem(int maxQueens): queensCount(maxQueens) {
        chessTable = new bool*[queensCount];
        for (int i = 0; i < queensCount; i++) {
            chessTable[i] = new bool[queensCount];
            for (int j = 0; j < queensCount; j++) {
                chessTable[i][j] = false;
            }
        }
    }

    vector<string> solve() {
        if(setQueens(0)){
            return printTable();
        }
        return vector<string>();
    }

    bool setQueens(int colIdx) {
        if (colIdx == queensCount) {
            return true;
        }

        for (int rowIdx = 0; rowIdx < queensCount; rowIdx++) {

            if (placeValid(rowIdx, colIdx)) {
                // Initially setting the flag as the place is a valid one.
                chessTable[rowIdx][colIdx] = true;

                // Now we can check whether the next queen can be placed.
                if (setQueens(colIdx + 1)) {
                    return true;
                }
                // If we come here means, we failed to place the next queen. so backtrack.
                chessTable[rowIdx][colIdx] = false;

            }
        }

        return false;
    }

    bool placeValid(int rowIdx, int colIdx) {
        for (int i = 0; i < colIdx; i++) {
            if (chessTable[rowIdx][i]) {
                return false;
            }
        }

        for (int i = rowIdx, j = colIdx; i >= 0 && j >= 0; i--, j--) {
            if (chessTable[i][j]) {
                return false;
            }
        }

        for (int i = rowIdx, j = colIdx; i < queensCount && j >= 0; i++, j--) {
            if (chessTable[i][j]) {
                return false;
            }
        }

        return true;
    }

    vector<string> printTable() {
        vector<string> table;
        for (int i = 0; i < queensCount; i++) {
            string str = "";
            for (int j = 0; j < queensCount; j++) {
                if (chessTable[i][j]) {
                    str += "*";
                }
                else {
                    str += "-";
                }
            }
            table.push_back(str);
        }
        return table;
    }

    ~NQueensProblem() {
        for (int i = 0; i < queensCount; i++) {
            delete [] chessTable[i];
        }
        delete[] chessTable;
    }
};


string toString(vector<string> vec) {
    string out = "";
    for (auto str : vec) {
        out += str;
    }
    return out;
}

TEST(NQueensProblemTest, TC1) {
    NQueensProblem tester(2);
    EXPECT_EQ("", toString(tester.solve()));
}

TEST(NQueensProblemTest, TC2) {
    NQueensProblem tester(3);
    EXPECT_EQ("", toString(tester.solve()));
}

TEST(NQueensProblemTest, TC3) {
    NQueensProblem tester(4);
    vector<string> res = {
        "--*-",
        "*---",
        "---*",
        "-*--"
    };
    EXPECT_EQ(toString(res), toString(tester.solve()));
}