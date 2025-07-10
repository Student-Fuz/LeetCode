#include <bits/stdc++.h>
using namespace std;

// 小顶堆  
class myCmp{
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int> rhs){
        return lhs.second > rhs.second;
    }
};

struct Edge {
    int to;     // 邻接顶点
    int val;    // 边的权重

    Edge(int t, int w): to(t), val(w) {} // 构造函数
};

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<list<Edge>> grid(n+1);

    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2, val));
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n+1, INT_MAX);

    vector<bool> visited(n+1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq;

    minDist[start] = 0;
    
    pq.push(pair<int, int>(start, 0));

    while(!pq.empty()){
        // 1. 选源点到哪个节点近且该节点未被访问过（通过优先队列来实现）
        pair<int, int> cur = pq.top();
        pq.pop();

        if(visited[cur.first]) continue;

        // 2. 将最近节点标记为访问过
        visited[cur.first] = true;

        // 3. 更新非访问节点到源点的距离（更新minDist数组）
        for(Edge edge : grid[cur.first]){
            if(!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]){
                minDist[edge.to] = minDist[cur.first] + edge.val;
                pq.push(pair<int, int>(edge.to, minDist[edge.to]));
            }
        }
    }

    if(minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;

    return 0;
}