#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 定义方向数组：左、右、上、下
int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int bfs(vector<vector<int>>& cityMap, int n, int m) {
    pair<int, int> start, pair<int, int> end;
    // 读取城市地图和起始位置、商家位置
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cityMap[i][j];
            if (cityMap[i][j] == 1) {
                start = {i, j};
            } else if (cityMap[i][j] == 2) {
                end = {i, j};
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    
    vector<vector<int>> count(n, vector<int>(m, 0));
    count[start.first][start.second] = 1; // 初始位置路径数量为1
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        // 如果到达商家的位置，返回此时的路径数量
        if (curr == end) {
            return count[curr.first][curr.second];
        }
        
        // 尝试四个方向移动
        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + directions[i][0];
            int ny = curr.second + directions[i][1];
            
            // 判断是否越界或者是不可经过的区域
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && cityMap[nx][ny] != -1) {
                if (count[nx][ny] == 0) { // 如果是第一次到达该位置
                    q.push({nx, ny});
                    count[nx][ny] = count[curr.first][curr.second]; // 继承父节点的路径数量
                } else { // 如果已经到达过该位置
                    count[nx][ny] += count[curr.first][curr.second]; // 累加路径数量
                }
            }
        }
    }
    
    return 0; // 如果到达不了商家位置，理论上不会执行到这里
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> cityMap(n, vector<int>(m));
    pair<int, int> start, end;
    

    
    // 使用BFS计算最短路径数量
    int result = bfs(cityMap, n, m);
    cout << result << endl;
    
    return 0;
}
