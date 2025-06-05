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

    vector<list<pair<int, int>>> grid;

    for(int i = 0; i < m+1; i++){
        int s, e, v;
        cin >> s >> e >> v;
        grid[s].push_back({e, v});
    }

    vector<bool> visited(n, false);
    vector<int> minDist(n, INT_MAX);
    // first--to second--minDist
    // 小顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq;
    pq.push({})


    return 0;
}