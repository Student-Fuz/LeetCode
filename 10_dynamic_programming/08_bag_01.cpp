#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1046

// 暴力--回溯
// int main() {

//     return 0;
// }

// 01dp问题
// 使用二维数组求解
int main() {

    // M件物品、N的容量
    int m, n;

    cin >> m >> n;

    vector<int> space(m, 0);
    vector<int> val(m, 0);
    for(int i = 0; i < m; i++){
        cin >> space[i];
    }

    for(int i = 0; i < m; i++){
        cin >> val[i];
    }

    vector<vector<int>> dp(m, vector<int>(n+1, 0));

    // 1. dp初始化
    // for(int i = 0; i < m; i++){
    //     dp[i][0] = 0;
    // }

    for(int i = 1; i <= n; i++){
        if(i >= space[0])
            dp[0][i] = val[0];
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j <= n; j++){
            if(j - space[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-space[i]] + val[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[m-1][n] << endl;

    return 0;
}