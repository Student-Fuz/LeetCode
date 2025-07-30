#include <bits/stdc++.h>
using namespace std;

// 情况一：如果我们找到入度为2的点，那么删一条指向该节点的边就行了。
// 情况二：只能删特定的一条边
// 情况三： 如果没有入度为2的点，说明 图中有环了（注意是有向环）。


int n = 1005; // n根据题目中节点数量而定，一般比节点数量大一点就好
// index--child val--father
vector<int> father = vector<int> (n, 0); // C++里的一种数组结构

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}
// 并查集里寻根的过程
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
// u-father、v-child
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}

pair<int, int> breakCircle(const vector<pair<int, int>>& edges){
    init();
    for(const auto& edge : edges){
        if(isSame(edge.first, edge.second)){
            return edge;
        }else{
            join(edge.first, edge.second);
        }
    }
}

bool isTreeafterRemove(const vector<pair<int, int>>& edges, pair<int, int>& targetEdge){
    init();
    for(const auto& edge : edges){
        if(edge == targetEdge) continue;
        if(isSame(edge.first, edge.second))
            return false;
        join(edge.first, edge.second);
    }
    return true;
}

int main() {

    cin >> n;

    init();
    vector<int> inDegree(n+1, 0);
    vector<pair<int, int>> edges;

    for(int i = 0; i < n; i++){
        int s, t;
        cin >> s >> t;
        edges.push_back({s, t});
        inDegree[t]++;
    }

    vector<pair<int, int>> cand;
    for(int i = n-1; i >= 0; i--){
        if(inDegree[edges[i].second] == 2){
            cand.push_back(edges[i]);
        }
    }

    if(cand.size() == 0){
        pair<int, int> edge = breakCircle(edges);
        cout << edge.first << " " << edge.second << endl;
        return 0;
    }
        
    if(isTreeafterRemove(edges, cand[0])){
        cout << cand[0].first << " " << cand[0].second << endl;
    }else{
        cout << cand[1].first << " " << cand[1].second << endl;
    }

    return 0;
}

// 错误---想法不成立
// 反例
// 6
// 1 2
// 2 3
// 6 5
// 5 4
// 3 4
// 1 6
// 输出结果：5 4
// 正确结果：3 4
// int main() {

//     cin >> n;

//     init();
//     unordered_map<int, int> inDegree;
//     vector<int> directFather(n+1);

//     for(int i = 0; i < n; i++){
//         // u-father、v-child
//         int u, v;
//         cin >> u >> v;
//         inDegree[v]++;
//         if(inDegree[v] == 2){
//             if(!isSame(u, v)){
//                 // 删除另一边
//                 cout << directFather[v] << " " << v << endl;
//             }
//             else
//                 cout << u << " " << v << endl;
//             return 0;
//         }
//         if(!isSame(u, v)){
//             directFather[v] = u;
//             join(u, v);
//         }  
//         else{
//             // 环
//             cout << u << " " << v << endl;
//             return 0;
//         }  
//     }

//     return 0;
// }