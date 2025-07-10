#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/target-sum/description/

// 回溯
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
        
//     }
// };

// 返回值--背包装满的装法
// 动态规划
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto& num : nums) sum += num;
        if (abs(target) > sum) return 0; // 此时没有方案
        if ((target + sum) % 2 == 1) return 0; // 此时没有方案

        // pos + neg = sum
        // pos - neg = target
        // pos = (sum + target)/2
        int bagSize = (sum + target)/2;

        vector<int> dp(bagSize+1, 0);
        dp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            for(int j = bagSize; j >= nums[i]; j--){
                dp[j] += dp[j-nums[i]];
            }
        }

        return dp[bagSize];

    }
};

int main() {

    return 0;
}
