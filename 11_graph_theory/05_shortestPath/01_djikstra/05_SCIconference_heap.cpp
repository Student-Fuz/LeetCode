#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1047

class myCmp{
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
        return lhs.second > rhs.second;
    }
};

int main() {

    int n, m;

    cin >> n >> m;

    vector<list<pair<int, int>>> grid(n+1);

    for(int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        grid[s].push_back({e, v});
    }

    vector<bool> visited(n+1, false);
    vector<int> minDist(n+1, INT_MAX);
    minDist[1] = 0;
    // first--to second--minDist
    // 小顶堆
    // 比较second
    priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq;
    int start = 1;
    int end = n;
    pq.push({start, 0});

    while(!pq.empty()){

        // 1. 选择离得最近的未访问节点
        auto node = pq.top();
        pq.pop();

        // 2. 访问node
        visited[node.first] = true;

        // 3. 更新minDist
        for(auto& to : grid[node.first]){
            if(visited[to.first] == false){
                minDist[to.first] = min(minDist[to.first], minDist[node.first] + to.second);
                pq.push({to.first, minDist[to.first]});
            }
        }
    }

    if(minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;

    return 0;
}