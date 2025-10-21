#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, X, Y, Z;
    if (!(cin >> M >> X >> Y >> Z)) return 0;

    const int BASE = 1000; 
    int N = BASE + M + 5; 
    vector<vector<Edge>> g(N);

    for (int i = 0; i < M; i++) {
        int price, n;
        cin >> price >> n;
        vector<int> st(n);
        for (int j = 0; j < n; j++) cin >> st[j];
        int lineNode = BASE + i; 
        for (int s : st) {
            // base以下存储号线，价格
            g[s].push_back({lineNode, price}); 
            // base以上存储0元可达节点，价格（0元）
            g[lineNode].push_back({s, 0}); 
        }
    }

    const long long INF = 1e15;
    vector<long long> dist(N, INF);
    // first--distance, second--node;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[X] = 0;
    pq.push({0, X});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        long long d = cur.first;
        int u = cur.second;
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