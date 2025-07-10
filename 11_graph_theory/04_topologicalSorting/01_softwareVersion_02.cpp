#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1191

// int main() {

//     int n, m;

//     cin >> n >> m;

//     // 可能有多个father所以不能这样写
//     vector<int> father(n, -1);
//     vector<int> inDegree(n, 0);

//     for(int i = 0; i < m; i++){
//         int s ,t;
//         cin >> s >> t;

//         father[t] = s;
//         inDegree[s]++;
//     }

//     vector<int> result;
//     queue<int> q;
//     // 找到入度为0的节点
//     for(int i = 0; i < n; i++){
//         if(inDegree[i] == 0){
//             q.push(i);
//             result.push_back(i);
//         }
//     }

//     while(!q.empty()){
//         int node = q.front();
//         q.pop();

//         if(father[node] != -1){
//             inDegree[father[node]]--;
//             if(inDegree[father[node]] == 0){
//                 q.push(father[node]);
//                 result.push_back(father[node]);
//             }
//         }
//     }

//     if(result.size() != n) cout << -1 << endl;
//     else{
//         // for(int i = 0; i < result.size(); i++){
//         //     if(i == 0) cout << result[0];
//         //     else cout << " " << result[i];
//         // }
//         for(int i = result.size()-1; i >= 0; i--){
//             if(i == result.size()-1) cout << result[i];
//             else cout << " " << result[i];
//         }
//         cout << endl;
//     }
//     return 0;
// }


int main(){
    int n, m;

    cin >> n >> m;

    vector<vector<int>> children(n);
    vector<int> inDegree(n, 0);

    // 父->子
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        children[s].push_back(t);
        inDegree[t]++;
    }

    queue<int> q;
    vector<int> result;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int i = 0; i < children[node].size(); i++){
            inDegree[children[node][i]]--;
            if(inDegree[children[node][i]] == 0){
                q.push(children[node][i]);
            }
        }
    }

    if(result.size() == n){
        for(int i = 0; i < n; i++){
            if(i == 0) cout << result[i];
            else cout << " " << result[i];
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}