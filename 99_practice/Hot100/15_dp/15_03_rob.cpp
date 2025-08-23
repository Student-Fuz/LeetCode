#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/house-robber/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, 0);

        for(int i = 0; i < nums.size(); i++){
            dp[i+2] = max(dp[i+1], dp[i]+nums[i]);
        }

        return dp.back();
    }
};

int main() {

    return 0;
}