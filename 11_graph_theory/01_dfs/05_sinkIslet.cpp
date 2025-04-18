#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& thisLand, bool& isedge, int x, int y){
    visited[x][y] = true;
    thisLand.push_back({x, y});

    for(int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];

        if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
            isedge = true;
            continue;
        }

        if(!visited[nextx][nexty] && grid[nextx][nexty] == 1){
            dfs(grid, visited, thisLand, isedge, nextx, nexty);
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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                bool isedged = false;
                vector<pair<int, int>> thisLand;
                dfs(grid, visited, thisLand, isedged, i, j);
                if(!isedged){
                    for(const auto& [x, y] : thisLand){
                        grid[x][y] = 0;
                    }
                }
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(m > 0)
    //         cout << " " << grid[i][j];
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(m > 0)
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}