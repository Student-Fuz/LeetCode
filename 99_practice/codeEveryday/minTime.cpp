#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/find-the-minimum-amount-of-time-to-brew-potions/?envType=daily-question&envId=2025-10-09

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + mana[i-1] * skill[j-1];
            }

            for(int j = n-1; j > 0; j--){
                dp[i][j] = dp[i][j+1] - mana[i-1] * skill[j];
            }
        }
        return dp[m][n];
    }
};

int main() {

    return 0;
}