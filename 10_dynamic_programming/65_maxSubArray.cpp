#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return false;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxVal = nums[0];

        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        
        return maxVal;
    }
};

int main() {

    return 0;
}
