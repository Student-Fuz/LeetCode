#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

// 贪心 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            profit = max(0, prices[i] - prices[i-1]);
            maxProfit += profit;
        }

        return maxProfit;
    }
};

// dp TODO

int main() {

    return 0;
}