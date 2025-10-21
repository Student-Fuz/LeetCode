#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2*k, 0));
        for(int i = 0; i < 2*k; i+=2){
            dp[0][i] = 0 - prices[0];
        }
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], 0-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
            for(int j = 1; j < k; j++){
                dp[i][2*j] = max(dp[i-1][2*j], dp[i-1][2*j-1]-prices[i]);
                dp[i][2*j+1] = max(dp[i-1][2*j+1], dp[i-1][2*j]+prices[i]);
            }
        }
        return dp.back().back();
    }
};

int main() {

    return 0;
}