#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int row, int col){
        // Boundary check
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0'){
            return;
        }

        // Mark the current cell as visited
        grid[row][col] = '0';

        // Explore all 4 directions
        dfs(grid, row + 1, col); // down
        dfs(grid, row - 1, col); // up 
        dfs(grid, row, col + 1); // right
        dfs(grid, row, col - 1); // left 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans{0};

        // Iterate over every cell in the grid
        for(int i{0}; i < grid.size(); ++i){
            for(int j{0}; j < grid[0].size(); ++j){
                
                // If the cell is land its the start of a new island
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j); // Sink the island using dfs
                }
            }
        }
        return ans;
    }
};