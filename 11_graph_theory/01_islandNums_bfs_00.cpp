#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void bfs(int x, int y, vector<vector<int>>& mat, vector<vector<bool>>& visited){
    visited[x][y] = true;

    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()){
        auto [curx, cury] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
    
            if(nextx < 0 || nextx >= mat.size() || nexty < 0 || nexty >= mat[0].size()) continue;
            
            if(mat[nextx][nexty] == 1 && visited[nextx][nexty] == false){
                visited[nextx][nexty] = true;
                q.push({nextx, nexty});
            }
        }
    }
}

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int num = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(mat[i][j] == 1 && visited[i][j] == false){
                num++;
                bfs(i, j, mat, visited);
           }
        }
    }

    cout << num;

    return 0;
}