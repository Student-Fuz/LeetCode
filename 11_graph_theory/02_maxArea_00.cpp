#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1172

vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void dfs(vector<vector<int>>& mat, vector<vector<bool>>& visited, int& area, int x, int y){
    visited[x][y] = true;
    area++;

    for(int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];

        if(nextx < 0 || nextx >= mat.size() || nexty < 0 || nexty >= mat[0].size()) continue;

        if(visited[nextx][nexty] == false && mat[nextx][nexty] == 1){
            dfs(mat, visited, area, nextx, nexty);
        }
    }
}

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    int maxArea = 0;
    int area = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == false && mat[i][j] == 1){
                area = 0;
                dfs(mat, visited, area, i, j);
                maxArea = max(area, maxArea);
            }
                
        }
    }

    cout << maxArea;

    return 0;
}
