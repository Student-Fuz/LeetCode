#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// 两天冷冻期呢？ k天冷冻期呢？
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0-持有股票 1-今天售出 2-今天冻结 3-今天可买
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][2]- prices[i], dp[i-1][3] - prices[i]));
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = dp[i-1][1];
            dp[i][3] = max(dp[i-1][3], dp[i-1][2]);
        }

        return max(dp[prices.size()-1][1], max(dp[prices.size()-1][2], dp[prices.size()-1][3]));
    }
};

int main() {

    return 0;
}