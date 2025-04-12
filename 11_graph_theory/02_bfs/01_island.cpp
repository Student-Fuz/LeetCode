#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
void bfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for(int i  = 0; i < 4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
    
            if(nextx < 0 || nextx == grid.size() || nexty < 0 || nexty == grid[0].size()) continue;
    
            if(!visited[nextx][nexty] && grid[nextx][nexty] == 1){
                q.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
    }

}

int main() {

    // 1. 处理输入
    int n, m;

    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    // 2. 计算岛屿数量
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int result = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){\
                result++;
                bfs(grid, visited, i, j);
            }
        }
    }

    cout << result << endl;

}