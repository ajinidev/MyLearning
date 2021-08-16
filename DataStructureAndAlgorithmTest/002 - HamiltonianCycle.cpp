#include "pch.h"
#include <string>
#include <vector>
using namespace std;

class HamiltonianCycle {
    int numVertex;
    int* path;
    vector<vector<int>> matrix;

    HamiltonianCycle(vector<vector<int>> matrix) : matrix(matrix) {
        numVertex = matrix.size();
        path = new int[numVertex];
    }

    vector<int> getHamiltonianPath() {
        path[0] = 0;
        if (findFeasibleSolution(1)) {
            printHamiltonianPath();
        }
    }

    bool findFeasibleSolution(int position) {

        if (position == numVertex) {
            if (matrix[path[position - 1]][path[0]] == 1) {
                return true;
            }
            return false;
        }

        for (int idx = 1; idx < numVertex; idx++) {
            if (isFeasible(idx, position)) {
                path[position] = idx;
                if (findFeasibleSolution(position + 1)) {
                    return true;
                }
                path[position] = 0;
            }
        }
        return false;
    }

    bool isFeasible(int vertIdx, int position) {
        // Check whether the nodes are connected or not.
        if (matrix[path[vertIdx - 1]][vertIdx] == 0) {
            return false;
        }

        // check whether the node is visited or not. if visited, then return false
        for (int i = 0; i < position; i++) {
            if (path[i] == vertIdx) {
                return false;
            }
        }
        return true;
    }

    vector<int> printHamiltonianPath() {
        vector<int> vec;
        for (int i = 0; i < numVertex; i++) {
            vec.push_back(path[i]);
        }
        return vec;
    }
};