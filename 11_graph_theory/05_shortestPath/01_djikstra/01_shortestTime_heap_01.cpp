#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1047

class MyCmp{
public:
    bool operator()(const pair<int, int>& l, const pair<int, int>& r){
        return l.second > r.second;
    }
};

// 高效-标准
int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n+1);
    for(int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        adjList[s].push_back({e, v});
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n+1, INT_MAX);
    minDist[1] = 0;

    vector<bool> visited(n+1, false);
    // first--node, second--dist
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> q;
    q.push({1, 0});

    while(!q.empty()){
        int node = q.top().first;
        int dist = q.top().second;
        q.pop();

        if(visited[node]) continue;
        visited[node] = true;

        for(int i = 0; i < adjList[node].size(); i++){
            int to = adjList[node][i].first;
            int to_dist = dist+adjList[node][i].second;
            if(visited[to] == false && to_dist < minDist[to]){
                minDist[to] = to_dist;
                q.push({to, to_dist});
            }
                
        }
    }
    
    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;

    return 0;
}

// 低效
int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n+1);
    for(int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        adjList[s].push_back({e, v});
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n+1, INT_MAX);
    minDist[1] = 0;

    vector<bool> visited(n+1, false);
    // first--node, second--dist
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> q;
    q.push({1, 0});

    while(!q.empty()){
        int node = q.top().first;
        int dist = q.top().second;
        q.pop();

        if(visited[node]) continue;
        visited[node] = true;
        minDist[node] = dist;

        for(int i = 0; i < adjList[node].size(); i++){
            int to = adjList[node][i].first;
            int to_dist = dist+adjList[node][i].second;
            if(visited[to] == false){
                q.push({to, to_dist});
            }  
        }
    }
    
    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;

    return 0;
}