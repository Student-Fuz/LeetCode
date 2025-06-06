#include <bits/stdc++.h>
using namespace std;

// 下一个节点是否能合法已经判断完了，传进dfs函数的就是合法节点。
// 右 上 下 左
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    for(int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        // 越界
        if(nextx < 0 || nextx == grid.size() || nexty < 0 || nexty == grid[0].size()) continue;
        if(visited[nextx][nexty] != true && grid[nextx][nexty] == 1){
            visited[nextx][nexty] = true;
            dfs(grid, visited, nextx, nexty);
        }
    }
}

int main() {

    // 1. 处理输入
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
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
            if(!visited[i][j] && grid[i][j] == 1){
                visited[i][j] = true;
                result++;
                dfs(grid, visited, i, j);
            }
        }
    }

    cout << result << endl;

    return 0;
}