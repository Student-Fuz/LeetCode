#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1047

int main() {

    int n, m;

    cin >> n >> m;

    vector<list<pair<int, int>>> grid(n+1);
    
    for(int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        grid[s].push_back({e, v});
    }

    vector<bool> visited(n+1, false);
    vector<int> minDist(n+1, INT_MAX);

    int start = 1;
    int end = n;

    minDist[1] = 0;

    // n步之内找到最短路
    for(int i = 1; i < n+1; i++){
 
        int minVal = INT_MAX;
        int cur = 1;

        // 1. 找到最近的未访问节点
        for(int j = 1; j < n+1; j++){
            if(visited[j] == false && minDist[j] < minVal){
                minVal = minDist[j];
                cur = j;
            }
        }

        // 2. 访问该节点
        visited[cur] = true;

        // 3. 更新最短距离
        for(const auto& dst : grid[cur]){
            minDist[dst.first] = min(minDist[dst.first], minDist[cur]+dst.second);
        }

    }

    if(minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl; 

    return 0;
}