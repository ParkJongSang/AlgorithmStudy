#include <queue>

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int board[100][100] = {0, };
        int ret = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};
        int width = grid[0].length();
        int height = grid.size();
        int boardWidth = width*3;
        int boardHeight = height*3;
        queue<pair<int, int> > q;
        
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(grid[i][j] == '/') {
                    board[3*i+2][3*j] = 1;
                    board[3*i+1][3*j+1] = 1;
                    board[3*i][3*j+2] = 1;
                } else if(grid[i][j] == '\\') {
                    board[3*i][3*j] = 1;
                    board[3*i+1][3*j+1] = 1;
                    board[3*i+2][3*j+2] = 1;
                }
            }
        }
        
        for(int i = 0; i < boardHeight; i++) {
            for(int j = 0; j < boardWidth; j++) {
                if(board[i][j] == 0) {
                    ret++;
                    board[i][j] = 1;
                    q.push({i, j});
                    while(!q.empty()) {
                        int cy = q.front().first;
                        int cx = q.front().second;
                        board[cy][cx] = 1;
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int nx = cx + dx[k];
                            int ny = cy + dy[k];
                            if(nx < boardHeight && ny < boardWidth && nx >= 0 && ny >= 0 && board[ny][nx] == 0) {
                                q.push({ny, nx});
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};
