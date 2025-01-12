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
    void dfs(vector<vector<int>>& grid, int row, int col, int& count){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0){
            return;
        }
        int ans{0};

        count++;

        // Mark as visited
        grid[row][col] = 0;

        dfs(grid, row + 1, col, count); // Up
        dfs(grid, row - 1, col, count); // Down
        dfs(grid, row, col + 1, count); // right
        dfs(grid, row, col - 1, count); // left
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_amount{0};

        for(int i{0}; i < grid.size(); ++i){
            for(int j{0}; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    
                    int ans{0};
                    dfs(grid, i, j, ans);
                    max_amount = max(max_amount, ans);
                }
            }
        }
        return max_amount;
    }
};