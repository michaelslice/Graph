#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Time complexity: O(m X n)
// Space Complexity: O(m X n)

    class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // Store the coordintes
        queue<pair<int, int>> q;
        
        // Count number of fresh oranges
        int fresh = 0;
        // Track time to rot all oranges
        int time = 0;

        for(int r{0}; r < grid.size(); ++r){
            for(int c{0}; c < grid[0].size(); ++c){
                // If fresh orange, increment orange count
                if(grid[r][c] == 1){
                    fresh++;
                }
                // If rotton orange push coordinates
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }

        // All valid directions for rotton orange to spread
        // right, left, up, down
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // As long as there are fresh oranges and rotton oranges to process
        while(fresh > 0 && !q.empty()){
            
            // Track number of rotton oranges
            int length = q.size();

            // Process all rotton oranges
            for(int i{0}; i < length; ++i){
                
                // Process the front oranges coordinates
                auto curr = q.front();
                q.pop();

                // Extract row and column coordinates
                int r = curr.first;
                int c = curr.second;

                // This part spreads the rotting effect to fresh oranges
                // by checking left, right, up, down oranges
                for(const auto& dir : directions){
                    // Recalculate the new coordinates 
                    // for the new cell being processed
                    int row = r + dir.first;
                    int col = c + dir.second;

                    // Boundary check
                    if(
                        row >= 0 && row < grid.size() && 
                        col >= 0 && col < grid[0].size() &&
                        grid[row][col] == 1
                      )
                      {

                        // Rot adjacent orange
                        grid[row][col] = 2;

                        // Add the newly rotted orange to the queue
                        q.push({row, col});

                        // Decrement count of fresh oranges
                        fresh--;
                      }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};