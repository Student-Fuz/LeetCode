#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1046

// 01dp问题
// 使用滚动数组求解----滚动数组-->空间上的优化
int main() {

    int m, n;

    cin >> m >> n;

    vector<int> weights(m, 0);
    vector<int> val(m, 0);
    for(int i = 0; i < m; i++){
         cin >> weights[i];
    }

    for(int i = 0; i < m; i++){
        cin >> val[i];
    }

    vector<int> dp(n+1, 0);

    for(int i = 0; i < m; i++){
        for(int j = n; j >= 0; j--){
            if(j >= weights[i])
                dp[j] = max(dp[j], dp[j-weights[i]] + val[i]);
            else
                dp[j] = dp[j];
        }
    }

    cout << dp[n] << endl;

    return 0;
}