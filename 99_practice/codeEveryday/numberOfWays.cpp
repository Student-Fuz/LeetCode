#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/description/?envType=daily-question&envId=2025-08-21

class Solution {
public:
    int numberOfWays(int n, int x) {
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 1;
            long long val = pow(i, x);
            for(int j = 0; j <= n; j++){
                if(j >= val){
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-val])%mod;
                }else{
                    dp[i][j] = dp[i-1][j];
                }

            }
        }
        return dp.back().back();
    }
};

int main() {

    return 0;
}