#include <bits/stdc++.h>
using namespace std;

// BFS


int main() {
    int n, k;

    cin >> n >> k;

    vector<vector<int>> graph(n+1);

    for(int i = 0; i < k ; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    // BFS
    queue<int> q;
    q.push(1);

    unordered_set<int> visited;
    visited.insert(1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++){
            if(visited.find(graph[cur][i]) == visited.end()){
                visited.insert(graph[cur][i]);
                q.push(graph[cur][i]);
            }
        }
    }

    if(visited.size() == n) cout << 1 << endl;
    else cout << -1 << endl;
    return 0;
}