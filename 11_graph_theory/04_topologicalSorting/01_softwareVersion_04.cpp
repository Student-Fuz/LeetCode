#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    unordered_map<int, int> inDegrees;
    unordered_map<int, vector<int>> children;
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        children[s].push_back(t);
        inDegrees[t]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegrees.find(i) == inDegrees.end()) q.push(i);
    }

    vector<int> r;
    while(!q.empty()){
        int father = q.front();
        r.push_back(father);
        q.pop();

        for(auto& child : children[father]){
            inDegrees[child]--;
            if(inDegrees[child] == 0) q.push(child);
        }
    }

    if(r.size() == n){
        for(int i = 0; i < r.size(); i++){
            if(i == 0){
                cout << r[i];
            }
            else{
                cout << " " << r[i];
            }
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}