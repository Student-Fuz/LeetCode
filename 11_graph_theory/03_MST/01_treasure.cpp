#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    int x, y, k;
    cin >> v >> e;

    vector<vector<int>> grid(v+1, vector<int>(v+1, 10001));
    
    for(int i = 0; i < e; i++){
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k; // 无向图 需要添加这行
    }

    vector<int> minDist(v+1, 10001);
    vector<bool> isInTree(v+1, false);

    minDist[1] = 0;

    // 只要要循环n-1次，建立n-1条边，就可以把n个节点的图连在一起
    for(int i = 1; i < v; i++){

        // 1. 选距离生成树最近的节点
        int cur = -1;
        int minVal = INT_MAX;
        for(int j = 1; j <= v; j++){
            if(!isInTree[j] && minDist[j] < minVal){
                minVal = minDist[j];
                cur = j;
            }
        }

        // ❗️无法继续扩展生成树，说明图不连通
        if(cur == -1) {
            cout << -1 << endl;
            return 0;
        }

        // 2. 标记最近节点加入生成树
        isInTree[cur] = true;

        // 3. 更新非生成树节点到生成树的距离（即更新minDist数组）
        for(int j = 1; j <= v; j++){
            if(!isInTree[j] && grid[cur][j] < minDist[j]){
                minDist[j] = grid[cur][j];
            }
        }
    }

    // 统计结果
    int result = 0;
    for(int i = 2; i <= v; i++){
        result += minDist[i];
    }
    cout << result << endl;

    return 0;
}