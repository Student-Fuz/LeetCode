#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(n+1, INT_MAX));

    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n+1, INT_MAX);

    vector<bool> visited(n+1, false);

    minDist[start] = 0;

    for(int i = 0; i <= n; i++){
        int minVal = INT_MAX;
        int cur = 1;

        // 1、选择距离源点最近且未被访问的节点
        for(int v = 1; v <= n; v++){
            if(!visited[v] && minDist[v] < minVal){
                minVal = minDist[v];
                cur = v;
            }
        }

        // 2、标记节点已被访问
        visited[cur] = true;

        // 3、更新非访问节点到源点的距离（更新minDist数组）
        for(int v = 1; v <= n; v++){
            if(!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]){
                minDist[v] = minDist[cur] + grid[cur][v];
            }
        }
    }

    if(minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;

    return 0;
}