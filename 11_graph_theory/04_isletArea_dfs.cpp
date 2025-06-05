#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1173

vector<vector<int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void dfs(vector<vector<int>>& mat, vector<vector<bool>>& visited, bool& isedged, int& area, int x, int y){
    if(x == 0 || x == mat.size()-1 || y == 0 || y == mat[0].size()-1) isedged = true;
    visited[x][y] = true;
    area++;

    for(int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];

        if(nextx < 0 || nextx >= mat.size() || nexty < 0 || nexty >= mat[0].size()) continue;

        if(mat[nextx][nexty] == 1 && visited[nextx][nexty] == false){ 
            dfs(mat, visited, isedged, area, nextx, nexty);
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

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int totalArea = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1 && visited[i][j] == false){
                int area = 0;
                bool isedged = false;
                dfs(mat, visited, isedged, area, i, j);
                if(!isedged) totalArea += area;
            }
        }
    }

    cout << totalArea << endl;

    return 0;
}