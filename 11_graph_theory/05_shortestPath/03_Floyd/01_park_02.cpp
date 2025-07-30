#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1155

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 10001)));

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v][0] = w;
        dp[v][u][0] = w;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j][k] = min(dp[i][j][k-1], dp[i][k][k-1] + dp[k][j][k-1]);
            }
        }
    }

    int num;

    cin >> num;

    for(int i = 0; i < num; i++){
        int start, end;
        cin >> start >> end;
        int result = (dp[start][end][n] != 10001)? dp[start][end][n] : -1;
        cout << result;
        if(i < num-1) cout << endl;
    }

    return 0;
}