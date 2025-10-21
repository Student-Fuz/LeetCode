#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 1;
        if(prices.size() <= 1) return 0;
        int n = prices.size();
        vector<int> hold(n, 0);
        // 表示第i天及第i天之前不持有股票的最大收益
        vector<int> notHold(n, 0);

        hold[0] = -prices[0];

        for(int i = 1; i < prices.size(); i++){
            hold[i] = max(hold[i-1], (i-k-1 >= 0?notHold[i-k-1]:0)-prices[i]);
            notHold[i] = max(notHold[i-1], hold[i-1]+prices[i]);
        }

        return notHold.back();
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 1;
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> hold(n, 0);   // 持有股票
        vector<int> sold(n, 0);   // 卖出股票，冷静期开始
        vector<int> rest(n, 0);   // 休息状态，不持股
        
        hold[0] = -prices[0];
        sold[0] = 0;
        rest[0] = 0;
        
        for(int i = 1; i < n; ++i){
            hold[i] = max(hold[i-1], (i-k-1 >= 0 ? rest[i-k-1] : 0) - prices[i]);
            int x = hold[i-1] + prices[i];
            rest[i] = max(rest[i-1], x);
        }
        
        return rest[n-1];
        // return max(sold[n-1], rest[n-1]);
    }
};


int maxProfit(vector<int>& prices) {
    int k = 1;
    int n = prices.size();
    if(n == 0) return 0;
    vector<int> hold(n, 0);   // 持有股票
    vector<int> sold(n, 0);   // 卖出股票，冷静期开始
    vector<int> rest(n, 0);   // 休息状态，不持股
    
    hold[0] = -prices[0];
    sold[0] = 0;
    rest[0] = 0;
    
    for(int i = 1; i < n; ++i){
        hold[i] = max(hold[i-1], (i-k-1 >= 0 ? rest[i-k-1] : 0) - prices[i]);
        sold[i] = hold[i-1] + prices[i];
        rest[i] = max(rest[i-1], sold[i]);
    }
    
    return max(sold[n-1], rest[n-1]);
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 1;
        int n = prices.size();
        if(n == 0) return 0;

        // 0-hold, 1-can buy, 2-cooldown
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], ((i - k - 1 >= 0)? dp[i - k - 1][1] : 0) - prices[i]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][1] = max(dp[i-1][1], dp[i][2]);
        }

        return max(dp[n-1][1], dp[n-1][2]);
    }
};


int main() {

    return 0;
}