#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, X, Y, Z;
    cin >> M >> X >> Y >> Z;

    const int MAX_STATION = 500;
    const int BASE_LINE = 600; // 虚拟节点起始编号（大于500即可）
    vector<vector<Edge>> g(BASE_LINE + M + 5);

    int maxNode = max(X, Y);

    for (int i = 0; i < M; ++i) {
        int price, n;
        cin >> price >> n;
        vector<int> st(n);
        for (int j = 0; j < n; ++j) {
            cin >> st[j];
            maxNode = max(maxNode, st[j]);
        }
        int lineNode = BASE_LINE + i; // 虚拟节点编号
        for (int s : st) {
            // 上车：站点 -> 线路节点，费用 price
            g[s].push_back({lineNode, price});
            // 下车：线路节点 -> 站点，费用 0
            g[lineNode].push_back({s, 0});
        }
    }

    // Dijkstra
    const long long INF = 1e15;
    vector<long long> dist(maxNode + M + 10, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    
    dist[X] = 0;
    pq.push({0, X});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        if (u == Y) break;
        for (auto &e : g[u]) {
            int v = e.v, w = e.w;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[Y] == INF || dist[Y] > Z) cout << -1 << "\n";
    else cout << dist[Y] << "\n";

    return 0;
}