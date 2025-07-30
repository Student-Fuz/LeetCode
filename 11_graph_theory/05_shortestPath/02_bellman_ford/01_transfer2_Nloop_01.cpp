#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1153

// 对于不规定步数的单源最短路问题可以不使用层序结构编程，有的使用层序结构编程反而逻辑是混乱的

// 
int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n+1);
    for(int i = 0; i < m; i++){
        int s, t, v;
        cin >> s >> t >> v;
        adjList[s].push_back({t, v});
    }

    vector<int> minDist(n+1, INT_MAX);
    minDist[1] = 0;
    queue<int> q;
    q.push(1);
    bool nCFlag = false;

    for(int i = 0; i < n; i++){
        int len = q.size();
        vector<bool> isInQueue(n + 1, false);

        while(len != 0){
            int node = q.front();
            int dist = minDist[node];
            q.pop();
            for(int j = 0; j < adjList[node].size(); j++){
                int nextNode = adjList[node][j].first;
                int dist_to = adjList[node][j].second;
                if(i < n-1){
                    if((dist + dist_to) < minDist[nextNode]){
                        minDist[nextNode] = dist + dist_to;
                        if(isInQueue[nextNode] == false){
                            q.push(nextNode);
                            isInQueue[nextNode] = true;
                        } 
                    }

                }
                else{
                    if((dist + dist_to) < minDist[nextNode]){
                        nCFlag = true;
                    }
                }
            }
            len--;
        }
    }

    if(nCFlag) cout << "circle" << endl;
    else{
        if(minDist[n] == INT_MAX) cout << "unconnected" << endl;
        else cout <<  minDist[n] << endl;
    }

    return 0;
}