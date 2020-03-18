#include <queue>
#include <vector>

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        
        queue<pair<int, int> > q;
        int ret = 0;
        int height = grid.size();
        int width = grid[0].size();
        
        for(int y = 0; y < height; y++) {
            for(int x = 0; x < width; x++) {
                if(grid[y][x] == '1') {
                    grid[y][x] = '2';
                    q.push({y, x});
                    ret++;
                    
                    while(!q.empty()) {
                        int cy = q.front().first;
                        int cx = q.front().second;
                        q.pop();
                        
                        for(int i = 0; i < 4; i++) {
                            int ny = cy + dy[i];
                            int nx = cx + dx[i];
                            if(ny >= 0 && ny < height && nx >= 0 && nx < width && grid[ny][nx] == '1') {
                                q.push({ny, nx});
                                grid[ny][nx] = '2';
                            }
                        }
                    }
                }
            }
        }
        
        return ret;
    }
};
