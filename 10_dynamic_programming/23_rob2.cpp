#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robRange(vector<int>& nums, int begin, int end){
        // 左闭右开
        if(end - begin <= 0) return -1;
        if(end - begin == 1) return nums[begin];
        if(end - begin == 2) return max(nums[begin], nums[begin+1]);
        vector<int> dp(end-begin);
        dp[0] = nums[begin];
        dp[1] = max(nums[begin], nums[begin+1]);

        for(int i = begin+2; i < end; i++){
            dp[i-begin] = max(dp[i-begin-1], dp[i-begin-2]+nums[i]);
        }
        return dp.back();
    }

    int rob(vector<int>& nums) {
        if(nums.size() <= 0) return -1;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int result1 = robRange(nums, 0, nums.size()-1);
        int result2 = robRange(nums, 1, nums.size());
        return max(result1, result2);

        // return 
    }
};

int main() {

    return 0;
}
