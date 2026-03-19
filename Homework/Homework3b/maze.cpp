#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include "Grid.h"
#include <vector>
using namespace std;

bool find_maze_path(Grid& grid, int row, int col, int level, vector<string>& solution) {
    //if we are out of bounds
    if (row < 0 || row >= grid.height() || col < 0 || col >= grid.width() || level < 0 || level >= grid.depth()) {
        return false;
    }
    //if we already visited the spot or an invalid path
    if (grid.at(row,col,level) != 1) {
        return false;
    }
    // append your current location in the maze to your solution data structure when you've determined that you are at a valid location
    grid.at(row,col,level) = 2;
    solution.push_back(to_string(row) + " " + to_string(col) + " " + to_string(level));
    //if we are at the end of the maze
    if (row == grid.height()-1 && col == grid.width()-1 && level == grid.depth()-1) {
        return true;
    }
    //Traverse the maze by recursing through`row + 1`, `row - 1`, `col + 1`, etc. one at a time
    if (find_maze_path(grid, row + 1, col, level, solution) ||
        find_maze_path(grid, row - 1, col, level, solution) ||
        find_maze_path(grid, row, col + 1, level, solution) ||
        find_maze_path(grid, row, col - 1, level, solution) ||
        find_maze_path(grid, row, col, level + 1, solution) ||
        find_maze_path(grid, row, col, level - 1, solution)
        ) {
        return true;
    }
    solution.pop_back();
    return false;

}

int main(int argc, char* argv[]) {
    // Write your code here
    ifstream mazeFile(argv[1]);
    ofstream mazePath(argv[2]);
    vector<string>mazeSolution;
    Grid myGrid;
    mazeFile >> myGrid;
    if (find_maze_path(myGrid,0,0,0,mazeSolution)) {
        mazePath << "SOLUTION" <<endl;
        for (auto stringPath: mazeSolution) {
            mazePath << stringPath << endl;
        }
    }else {
        mazePath << "NO SOLUTION" << endl;
    }
    return 0;
}
