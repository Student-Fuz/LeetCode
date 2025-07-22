#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1191

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> children(n);
    vector<int> inDegree(n, 0);
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;

        children[s].push_back(t);
        inDegree[t]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    vector<int> result;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int i = 0; i < children[node].size(); i++){
            int child = children[node][i];
            inDegree[child]--;
            if(inDegree[child] == 0){
                q.push(child);
            }
        }
    }

    if(result.size() == n){
        for(int i = 0; i < result.size(); i++){
            if(i == 0) cout << result[0];
            else cout << " " << result[i] ;
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
