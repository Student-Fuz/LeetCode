#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/partition-equal-subset-sum/description/

// 小优化
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0) return false;

        int sum = 0;
        for(auto& num : nums){
            sum += num;
        }

        // 奇数
        if(sum%2 == 1) return false;

        int target = (int)sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, false));

        for(int i = 0; i < nums.size(); i++){
            dp[i][0] = true;
        }

        if(nums[0] > target) return false;
            dp[0][nums[0]] = true;

        // 剪枝1--遇到 nums[i] > target return false
        // 剪枝2--遇到 dp[i][target] return true
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > target) return false;
            for(int j = 0; j <= target; j++){
                if(dp[i-1][j]){
                    dp[i][j] = true;
                    int sum = j + nums[i];
                    if(sum <= target)
                        dp[i][sum] = true;
                }
            }
            if(dp[i][target]) return true;
        }

        return dp[nums.size()-1][target];
    }
};

// 不排序
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0) return false;

        int sum = 0;
        for(auto& num : nums){
            sum += num;
        }

        // 奇数
        if(sum%2 == 1) return false;

        int target = (int)sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, false));

        for(int i = 0; i < nums.size(); i++){
            dp[i][0] = true;
        }

        if(nums[0] > target) return false;
            dp[0][nums[0]] = true;

        // 剪枝1--遇到 nums[i] > target return false
        // 剪枝2--遇到 dp[i][target] return true
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > target) return false;
            for(int j = 0; j <= target; j++){
                if(j - nums[i] >= 0){
                    dp[i][j] = dp[i-1][j-nums[i]];
                }
                // dp[i][j] = dp[i][j] || dp[i-1][j];
                if(dp[i-1][j]) dp[i][j] = true;
            }
            if(dp[i][target]) return true;
        }

        return dp[nums.size()-1][target];
    }
};

int main() {

    return 0;
}
