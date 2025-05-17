#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1191


// // 哈希表
// int main() {

//     int n, m;

//     cin >> n >> m;

//     unordered_map<int, vector<int>> children;
//     unordered_map<int, int> inDegree;

//     // 1. 处理输入
//     for(int i = 0; i < m; i++){
//         int s, t;
//         cin >> s >> t;
//         children[s].push_back(t);
//         if(inDegree.find(s) == inDegree.end())  
//             inDegree[s] = 0;
//         inDegree[t]++;
//     }

//     // 2. 计算
//     // 从入度为0开始BFS
//     queue<int> q;
//     for(const auto& pair : inDegree){
//         if(pair.second == 0)
//             q.push(pair.second);
//     }

//     vector<int> result;
//     while(!q.empty()){
//         int father = q.front();
//         result.push_back(father);
//         q.pop();

//         for(const auto& child : children[father])
//             q.push(child);
//     }

//     // 3. 处理输出
//     for(int i = 0; i < result.size(); i++){
//         if(i == 0) cout << result[i];
//         else cout << " " << result[i];
//     }

//     return 0;
// }

// 数组
int main() {

    int n, m;

    cin >> n >> m;

    // 需要inDegree
    // 1. 找到开始节点
    // 2. 节点可能有多个父亲
    vector<vector<int>> children(n);
    vector<int> inDegree(n, 0);

    // 1. 处理输入
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        children[s].push_back(t);
        inDegree[t]++;
    }

    // 2. 计算
    // 从入度为0开始BFS
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    vector<int> result;
    while(!q.empty()){
        int father = q.front();
        result.push_back(father);
        q.pop();

        for(const auto& child : children[father]){
            inDegree[child]--;
            if(inDegree[child] == 0)
                q.push(child);
        }
            
    }

    // 判断是否有环
    // 方法一：
    // 如果还要节点入度不为0，则有环
    for(int i = 0; i < inDegree.size(); i++){
        if(inDegree[i] > 0){
            cout << -1 << endl;
            return 0;
        }     
    }

    // 方法二：
    // 如果result的大小不为n
    if(result.size() != n){
        cout << -1 << endl;
        return 0;
    }   

    // 3. 处理输出
    for(int i = 0; i < result.size(); i++){
        if(i == 0) cout << result[i];
        else cout << " " << result[i];
    }

    return 0;
}