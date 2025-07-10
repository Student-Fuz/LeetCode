#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1047

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> mat(n+1, vector<int>(n+1, INT_MAX));

    for(int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        mat[s][e] = v;
    }

    vector<int> minDist(n+1, INT_MAX);
    vector<bool> visited(n+1, false);

    int start = 1;
    int end = n;

    minDist[start] = 0;

    for(int i = 1; i < n+1; i++){
        int minVal = INT_MAX;
        int cur = 1;

        // 1. 找到距离最近的未访问的节点
        for(int j = 1; j < n+1; j++){
            if(visited[j] == false && minDist[j] < minVal){
                minVal = minDist[j];
                cur = j;
            }
        }

        // 2. 访问该节点
        visited[cur] = true;

        // 3. 更新最短距离
        for(int j = 1; j < n+1; j++){
            if(visited[j] == false && mat[cur][j] != INT_MAX){
                minDist[j] = min(minDist[j], minDist[cur] + mat[cur][j]);
            }
        }

    }

    if(minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;

    return 0;
}