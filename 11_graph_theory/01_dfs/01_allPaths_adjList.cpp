#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// m2: 邻接矩阵
void dfs(vector<list<int>>& graph, vector<vector<int>>& result, vector<int>& path, int cur, int N){
    if(cur == N){
        result.push_back(path);
        return;
    }

    for(const int& i : graph[cur]){
        path.push_back(i);
        dfs(graph, result, path, i, N);
        path.pop_back();
    }
}

int main() {
    int N, M;
    // 1. 处理输入
    cin >> N >> M;

    vector<list<int>> graph(N+1);
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    // 2. 计算所有路径
    vector<vector<int>> result;
    vector<int> path;

    path.push_back(1);
    dfs(graph, result, path, 1, N);

    // 3. 处理输出
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size()-1; j++){
            cout << result[i][j] << " ";
        }
        cout << result[i].back() << endl;
    }

    return 0;
}