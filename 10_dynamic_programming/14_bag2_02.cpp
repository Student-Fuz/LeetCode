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

    vector<int> dp(v+1, 0);

    // for(int i = 0; i < n; i++){
    //     for(int j = weights[i]; j <= v; j++){
    //         dp[j] = max(dp[j], dp[j-weights[i]] + val[i]);
    //     }   
    // }

    for(int i = 0; i <= v; i++){
        for(int j = 0; j < n; j++){
            if(i >= weights[j])
                dp[i] = max(dp[i], dp[i-weights[j]] + val[j]);
        }
    }

    cout << dp[v] << endl;

    return 0;
}