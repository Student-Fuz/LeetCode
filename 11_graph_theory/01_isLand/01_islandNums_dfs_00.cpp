#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<bool>>& visited){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        // 边界判断
        if(next_x < 0 || next_x >= matrix.size() || next_y < 0 || next_y >= matrix[0].size()) continue;

        if(visited[next_x][next_y] == false && matrix[next_x][next_y] == 1){
            dfs(next_x, next_y, matrix, visited);
        }
    }


}

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            matrix[i][j] = val;
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int nums = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && matrix[i][j] == 1){
                dfs(i, j, matrix, visited);
                nums++;
            }
        }
    }

    cout << nums;
    return 0;
}