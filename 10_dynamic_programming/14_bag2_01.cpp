#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1052

int main() {

    int n, v;
    cin >> n >> v;
    if(n == 0) return 0;

    vector<int> weights(n);
    vector<int> val(n);

    for(int i = 0; i < n; i++){
        cin >> weights[i];
        cin >> val[i];
    }

    vector<vector<int>> dp(n, vector<int>(v+1, 0));
    for(int i = 0; i <= v; i++){
        dp[0][i] = i / weights[0] * val[0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= v; j++){
            if (j >= weights[i])
                dp[i][j] = max(dp[i-1][j], dp[i][j - weights[i]] + val[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n-1][v] << endl;

    return 0;
}