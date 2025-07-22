#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main() {

    return 0;
}