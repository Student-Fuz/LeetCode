#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1053

class MyCmp{
public:
    bool operator()(const pair<int, int>& l, const pair<int, int>& r){
        return l.second > r.second;
    }
};

int main() {

    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> adjList(v+1);
    for(int i = 0; i < e; i++){
        int v1, v2, val;
        cin >> v1 >> v2 >> val;
        adjList[v1].push_back({v2, val});
        adjList[v2].push_back({v1, val});
    }

    int start = 1, end = v;
    vector<int> minCost(v+1, INT_MAX);
    minCost[start] = 0;
    vector<bool> visited(v+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> pq;
    pq.push({start, 0});

    while(!pq.empty()){
        int node = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if(visited[node] == true) continue;
        visited[node] = true;

        for(int i = 0; i < adjList[node].size(); i++){
            int to = adjList[node][i].first;
            int price = adjList[node][i].second;
            if(visited[to] == false && price < minCost[to]){
                minCost[to] = price;
                pq.push({to, minCost[to]});
            }
        }
    }

    int path = 0;
    for(int i = 1; i < minCost.size(); i++){
        if(minCost[i] == INT_MAX){
            cout << -1 << endl;
            return 0;
        }
        path += minCost[i];
        // path = max(path, minCost[i]);
    }
    cout << path << endl;
    return 0;
}