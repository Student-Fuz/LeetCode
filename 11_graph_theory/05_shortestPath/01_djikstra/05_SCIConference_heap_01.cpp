#include <bits/stdc++.h>
using namespace std;

class MyCmp{
public:
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> adjList(n+1);
    for(int i = 0; i < m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        adjList[s].push_back({e, v});
        adjList[e].push_back({s, v});
    }

    int start = 1;
    int end = n;

    priority_queue<vector<int>, vector<vector<int>>, MyCmp> pq;
    for(int i = 0; i < adjList[start].size(); i++){
        pq.push(adjList[start][i]);
    }

    return 0;
}