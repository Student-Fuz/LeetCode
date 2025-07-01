#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/coin-change-ii/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount+1, 0);
        dp[0] = 1;

        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];

    }
};

int main() {

    return 0;
}
