#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void dfs(vector<vector<int>>& mat, vector<vector<bool>>& visited, vector<pair<int, int>>& thisLand, bool& isEdged, int x, int y){
    visited[x][y] = true;
    thisLand.push_back({x, y});
    if(isEdged || x == 0 || x == mat.size()-1 || y == 0 || y == mat[0].size()-1) isEdged = true;
    for(int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];

        if(nextx < 0 || nextx >= mat.size() || nexty < 0 || nexty >= mat[0].size()) continue;

        if(mat[nextx][nexty] == 1 && visited[nextx][nexty] == false)
            dfs(mat, visited, thisLand, isEdged, nextx, nexty);
    }
};

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1 && visited[i][j] == false){
                vector<pair<int, int>> thisIsland;
                bool isEdged = false;
                dfs(mat, visited, thisIsland, isEdged, i, j);
                if(!isEdged){
                    for(int i = 0; i < thisIsland.size(); i++){
                        mat[thisIsland[i].first][thisIsland[i].second] = 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j == 0) cout << mat[i][j];
            else cout << " " << mat[i][j];
        }
        cout << endl;
    }


    return 0;
}