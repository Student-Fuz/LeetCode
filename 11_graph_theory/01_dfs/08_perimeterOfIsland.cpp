#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int main() {
    // 处理输入
    int n, m;

    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int perimeter = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                for(int k = 0; k < 4; k++){
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];
                    if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
                        perimeter++;
                        continue;
                    } 
                    if(grid[nextx][nexty] == 0) perimeter++;
                }
            }
        }
    }

    cout << perimeter << endl;

    return 0;
}