#include <bits/stdc++.h>
using namespace std;

// https://kamacoder.com/problempage.php?pid=1067

int main() {

    int n, m;

    cin >> n >> m;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i >= j){
                dp[i] += dp[i-j];
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
