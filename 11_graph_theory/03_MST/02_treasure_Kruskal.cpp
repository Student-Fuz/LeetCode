#include <bits/stdc++.h>
using namespace std;

// https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0053.%E5%AF%BB%E5%AE%9D-Kruskal.md

int n = 1005; // n根据题目中节点数量而定，一般比节点数量大一点就好
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

// 将 v-u 这条边加入并查集
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}

struct Edge{
    int l, r, val;
};

int main() {

    int v, e;
    cin >> v >> e;

    vector<Edge> edges;
    for(int i = 0; i < e; i++){
        int v1, v2, val;
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }

    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2){
        return e1.val < e2.val;
    });

    init();
    int path = 0;
    for(int i = 0; i < e; i++){
        if(!isSame(edges[i].l, edges[i].r)){
            join(edges[i].l, edges[i].r);
            path += edges[i].val;
        }
    }
    cout << path << endl;

    return 0;
}