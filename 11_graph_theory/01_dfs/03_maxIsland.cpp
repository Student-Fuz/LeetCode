#include <bits/stdc++.h>
using namespace std;

// dfs
vector<vector<int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area, int x, int y){
    visited[x][y] = true;
    area += 1;
    for(int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];

        if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;

        if(!visited[nextx][nexty] && grid[nextx][nexty] == 1){
            dfs(grid, visited, area, nextx, nexty);
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

    // 2. 计算
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int area = 0;
    int maxArea = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                area = 0;
                dfs(grid, visited, area, i, j);
                maxArea = max(maxArea, area);
            } 
        }
    }

    // 3. 处理输出
    cout << maxArea << endl;


    return 0;
}