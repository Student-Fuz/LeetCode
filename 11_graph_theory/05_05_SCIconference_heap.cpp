#include <bits/stdc++.h>
using namespace std;

class myCmp{
public:
    bool operator()(pair<int, int> l, pair<int, int> r){
        return l.second > r.second;
    }
};

int main() {

    int n, m;

    cin >> n >> m;

    vector<list<pair<int, int>>> adjList(n+1);

    for(int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        adjList[s].push_back({e, v});
    }

    vector<int> minDist(n+1, INT_MAX);
    minDist[1] = 0;

    // 小顶堆
    // first--to second--cost 
    priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq;

    pq.push({1, 0});
    vector<int> visited(n+1);

    while(!pq.empty()){
        pair<int, int> node = pq.top();
        int node_idx = node.first;
        int node_cost = node.second;
        visited[node_idx] = true;


        pq.pop();
        for(auto to : adjList[node_idx]){
            if(visited[to.first] == false){
                minDist[to.first] = min(minDist[to.first], node_cost + to.second);
                pq.push({to.first, minDist[to.first]});
            }
        }

    }

    if(minDist[n] != INT_MAX) cout << minDist[n] << endl;
    else cout << -1 << endl;

    return 0;
}