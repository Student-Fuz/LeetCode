#include <bits/stdc++.h>
using namespace std;

// 最小生成树就是最小连通图

class Bigger{
public:
    bool operator()(pair<int, int>& l, pair<int, int>& r){
        return l.second > r.second;
    }
};

int main() {

    int n, m;

    cin >> n >> m;

    vector<list<pair<int, int>>> adjList(n+1);

    for(int i = 0; i < m; i++){
        int v1, v2, val;
        cin >> v1 >> v2 >> val;
        adjList[v1].push_back({v2, val});
        adjList[v2].push_back({v1, val});
    }

    // 小顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, Bigger> pq;

    vector<int> minDist(n+1, INT_MAX);
    vector<bool> visited(n+1, false);

    pq.push({1, 0});
    minDist[1] = 0;

    while(!pq.empty()){
        auto node = pq.top();
        int node_idx = node.first;
        int node_dis = node.second;

        pq.pop();

        if(visited[node_idx] == true) continue;
        visited[node_idx] = true;
        
        // 遍历次节点的附近未节点
        for(auto& near_node : adjList[node_idx]){
            int idx = near_node.first;
            int cost = near_node.second;

            if(visited[idx] == true) continue;
            minDist[idx] = min(minDist[idx], cost);
            pq.push({idx, minDist[idx]});
        }
    }

    int result = 0;
    for(int i = 1; i < minDist.size(); i++){
        if(minDist[i] == INT_MAX){
            cout << -1 << endl;
            return 0;
        }
        result += minDist[i];
    }

    cout << result << endl;

    return 0;
}