#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1153

// 低性能
// 未做每层重复节点注入剔除
int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n+1);
    for(int i = 0; i < m; i++){
        int s, t, v;
        cin >> s >> t >> v;
        adjList[s].push_back({t, v});
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    vector<int> minDist(n+1, INT_MAX);
    vector<int> minDist_copy(n+1);
    minDist[src] = 0;
    queue<int> q;
    q.push(src);

    for(int i = 0; i < k+1; i++){
        int len = q.size();
        minDist_copy = minDist;
        // vector<bool> isInQueue(n + 1, false);

        while(len != 0){
            int node = q.front();
            int dist = minDist_copy[node];
            q.pop();
            for(int j = 0; j < adjList[node].size(); j++){
                int nextNode = adjList[node][j].first;
                int dist_to = adjList[node][j].second;
                if((dist + dist_to) < minDist[nextNode]){
                    minDist[nextNode] = dist + dist_to;
                    q.push(nextNode);
                    // if(isInQueue[nextNode] == false){
                    //     q.push(nextNode);
                    //     isInQueue[nextNode] = true;
                    // } 
                }
            }
            len--;
        }
    }

    if(minDist[dst] == INT_MAX) cout << "unreachable" << endl;
    else cout <<  minDist[dst] << endl;

    return 0;
}