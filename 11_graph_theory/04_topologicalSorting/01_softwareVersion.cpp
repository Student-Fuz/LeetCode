#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1191

int main() {
    // 1. 处理输入
    int n, m;

    cin >> n >> m;

    // unordered_map<int, vector<int>> children;
    // unordered_map<int, int> in_degree;

    vector<vector<int>> children(n, vector<int>(0));
    vector<int> in_degree(n, 0);

    for(int i = 0; i < m; i++){
        int prev, cur;
        cin >> prev >> cur;

        children[prev].push_back(cur);
        in_degree[cur]++;
        // 为防止非法输入
        // 不写作 in_degree[cur] = 1; 且在后面代码中对减后入度值是否为0进行检查
        // in_degree[cur]++;
    }

    // 2. 计算结果
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> result;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        if(children[cur].size()){
            for(int i = 0; i < children[cur].size(); i++){
                in_degree[children[cur][i]]--;
                if(in_degree[children[cur][i]] == 0){
                    q.push(children[cur][i]);
                }
            }
        }

    }

    // 3. 处理输出
    if(result.size() == n){
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    else cout << -1 << endl;


    return 0;
}
