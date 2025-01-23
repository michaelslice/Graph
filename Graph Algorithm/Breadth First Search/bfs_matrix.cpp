#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// General Pattern

void bfs(vector<vector<int>>& matrix, int row, int col){

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Coordinates for... right, down, left, up
    vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    // Visited matrix to track visited cells
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Queue to store the current cell's position
    queue<pair<int, int>> q;

    // Mark the current cell as visited and enqueue it
    visited[row][col] = true;
    q.push({row, col});

    while(!q.empty()){
        // Get the current cell
        auto [curRow, curCol] = q.front();
        q.pop();

        // Process the current cell
        cout << "Visited cell: (" << curRow << ", " << curCol << ") with value " << matrix[curRow][curCol] << endl;

        // Explore neighbors
        for(auto [dRow, dCol] : directions){
            int newRow = curRow + dRow;
            int newCol =  curCol + dCol;

            if(newRow )
        }
    }
}


int main(){
    
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };


    return 0;
}