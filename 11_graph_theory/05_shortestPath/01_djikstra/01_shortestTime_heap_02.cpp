#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1047

class MyCmp{
public:
    bool operator()(const pair<int, int>& l, const pair<int, int>& r){
        return l.second > r.second;
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    // node, price
    vector<vector<pair<int, int>>> adjList(n+1);
    for(int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        adjList[s].push_back({e, v});
    }

    int start = 1, end = n;
    
    // node, dist
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> pq;
    vector<int> minDist(n+1, INT_MAX);
    minDist[start] = 0;
    vector<bool> visited(n+1, false);

    pq.push({start, 0});
    while(!pq.empty()){
        int node = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if(node == end) break;
        if(visited[node]) continue;
        visited[node] = true;

        for(int i = 0; i < adjList[node].size(); i++){
            int to = adjList[node][i].first;
            int price = adjList[node][i].second;

            if(visited[to] == false && dist+price < minDist[to]){
                minDist[to] = dist+price;
                pq.push({to, minDist[to]});
            }
        }
    }

    if(minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;

    return 0;
}