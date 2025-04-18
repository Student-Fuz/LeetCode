#include <bits/stdc++.h>
using namespace std;

int area = 0;
// 下一个节点是否能合法已经判断完了，传进dfs函数的就是合法节点。
// 右 上 下 左
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs(const vector<vector<int>>& grid, vector<vector<int>>& visited, int islandIndex, int x, int y){
    visited[x][y] = islandIndex;
    area++;
    for(int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        // 越界
        if(nextx < 0 || nextx == grid.size() || nexty < 0 || nexty == grid[0].size()) continue;
        if(visited[nextx][nexty] == 0 && grid[nextx][nexty] == 1){
            dfs(grid, visited, islandIndex, nextx, nexty);
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
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int islandIndex = 1;
    // key-islandIndex, value-area
    unordered_map<int, int> islandMap;
    int maxArea = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                area = 0;
                islandIndex++;
                dfs(grid, visited, islandIndex, i, j);
                islandMap[islandIndex] = area;
                maxArea = max(maxArea, area);
            }
        }
    }

    
    int curArea = 1;
    unordered_set<int> around;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0){
                curArea = 1;
                around.clear();
                for(int k = 0; k < 4; k++){
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];
                    if(nextx < 0 || nextx == grid.size() || nexty < 0 || nexty == grid[0].size()) continue;
                    if(visited[nextx][nexty] != 0 && around.count(visited[nextx][nexty]) == 0){
                        curArea += islandMap[visited[nextx][nexty]];
                        around.insert(visited[nextx][nexty]);
                    }
                        
                }
                maxArea = max(maxArea, curArea);
            }
        }
    }

    cout << maxArea << endl;

    return 0;
}