#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1173

vector<vector<int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void bfs(vector<vector<int>>& mat, vector<vector<bool>>& visited, bool& isedged, int& area, int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        area++;
        // visited[curx][cury] = true;
        if(curx == 0 || curx == mat.size()-1 || cury == 0 || cury == mat[0].size()-1) isedged = true;

        for(int i = 0; i < 4; i++){
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];

            if(nextx < 0 || nextx >= mat.size() || nexty < 0 || nexty >= mat[0].size()) continue;

            if(mat[nextx][nexty] == 1 && visited[nextx][nexty] == false){
                q.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
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
                bfs(mat, visited, isedged, area, i, j);
                if(!isedged) totalArea += area;
            }
        }
    }

    cout << totalArea << endl;

    return 0;
}