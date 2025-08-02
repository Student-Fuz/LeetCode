#include <bits/stdc++.h>
using namespace std;

// dfs2
void dfs(const vector<vector<int>>& graph, int node, vector<bool>& visited){
    vector<int> nextNodes = graph[node];
    for(const auto& nextNode : nextNodes){
        if(!visited[nextNode]){
            visited[nextNode] = true;
            dfs(graph, nextNode, visited);
        }
    }
}

int main() {
    int n, k;

    cin >> n >> k;

    vector<vector<int>> graph(n+1);

    for(int i = 0; i < k ; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    int start = 1;
    vector<bool> visited(n+1, false);
    visited[start] = true;
    dfs(graph, start, visited);

    for(int i = 1; i <= n; i++){
        if(visited[i] == false){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}