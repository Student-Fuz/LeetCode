#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/new-21-game/?envType=daily-question&envId=2025-08-17

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // 极端边界
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;
        if (n < k) return 0.0;

        // dp[i]: 从 0 出发，最终恰好停在 i 的“加权方案数”（=概率）
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        // window = 参与转移的窗口和 = dp[i-1] + ... + dp[i-maxPts]（只统计 <k 的项）
        double window = 1.0;  // 初始用于算 dp[1]，只有 dp[0]
        double ans = 0.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = window / maxPts;

            if (i < k) {
                // <k 还会继续抽牌，贡献给后面状态
                window += dp[i];
            } else {
                // >=k 游戏结束，累计答案
                ans += dp[i];
            }

            // 滑动窗口移出 i - maxPts 位置（仅当它属于 <k 的可转移状态）
            if (i - maxPts >= 0) {
                window -= dp[i - maxPts];
            }
        }
        return ans;
    }
};

// dp
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // 最终点数：[k, k-1+maxPts]
        if(k==0 || n >= k-1+maxPts)
            return 1;
        if(n < k)
            return 0;
        // res = dp[k -- n]/dp[k -- k-1+maxPts]
        double res;
        // i有多少种抽法
        vector<int> dp(k, 0);

        dp[0] = 1;
        for(int i = 1; i <= maxPts; i++){
            for(int j = 0; j < i && j < k; j++){
                dp[i] += dp[j];
            }
        }

        for(int i = maxPts+1; i <= k-1+maxPts; i++){
            for(int j = i-1; j >= i-maxPts; j--){
                dp[i] += dp[j];
            }
        }
        double a = 0;
        double b = 0;
        for(int i = k; i <= n; i++){
            a += dp[i];
        }
        for(int i = k; i <= k-1+maxPts; i++){
            b += dp[i];
        }

        
        return a/b;
    }
};

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // 最终点数：[k, k-1+maxPts]
        if(k==0 || n >= k-1+maxPts) return 1;
        if(n < k) return 0;
        // res = dp[k -- n]/dp[k -- k-1+maxPts]
        double res;
        // i有多少种抽法
        vector<int> dp(k, 0);

        dp[0] = 1;
        for(int i = 1; i <= maxPts; i++){
            for(int j = 0; j < i && j < k; j++){
                dp[i] += dp[j];
            }
        }

        for(int i = maxPts+1; i <= k-1+maxPts; i++){
            for(int j = i-1; j >= i-maxPts; j--){
                dp[i] += dp[j];
            }
        }
        double a = 0;
        double b = 0;
        for(int i = k; i <= n; i++){
            a += dp[i];
        }
        for(int i = k; i <= k-1+maxPts; i++){
            b += dp[i];
        }

        
        return a/b;
    }
};

int main() {

    return 0;
}