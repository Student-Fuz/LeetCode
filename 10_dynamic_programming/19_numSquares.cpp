#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX-1);
        dp[0] = 0;
        int bagSize = int(pow(n+1, 0.5));

        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= bagSize; j++){
                if(i >= j*j)
                    dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }

        return dp[n];
    }
};

int main() {

    int n = 10;
    // int bagSize = int(pow(n+1, 0.5));

    int bagSize = pow(n+1, 0.5);

    cout << bagSize << endl;

    return 0;
}
