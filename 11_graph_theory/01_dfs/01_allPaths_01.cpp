#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;


// 题目描述
// https://kamacoder.com/problempage.php?pid=1170

// m1: 邻接矩阵
void dfs(const vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path, int cur, int N){
    if(cur == N) {
        result.push_back(path);
        return;
    }

    for(int i = 1; i < N+1; i++){
        if(graph[cur][i] == 1){
            path.push_back(i);
            dfs(graph, result, path, i, N);
            path.pop_back();
        }
    }
}

int main() {
    // 1. 处理输入
    int N, M;

    cin >> N;
    cin >> M;

    vector<vector<int>> graph(N+1, vector<int>(N+1, 0));
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
    }

    // 2. 寻找路
    vector<vector<int>> result;
    vector<int> path;

    path.push_back(1);
    dfs(graph, result, path, 1, N);
    
    // 3. 打印输出
    if (result.size() == 0) cout << -1 << endl;
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size()-1; j++){
            cout << result[i][j] << " ";
        }
        cout << result[i].back() << endl;
    }

    return 0;
}


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