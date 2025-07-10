#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxLen = 1;
        vector<int> dp(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++){
            int j = i - 1;
            if(nums[i] > nums[j]){
                dp[i] = dp[j]+1;
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

int main() {

    return 0;
}
