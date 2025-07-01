#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/combination-sum-iv/description/

/* 
1. 外层物品内层背包--求组合 
2. 外层背包内层物品--求排列


思考：
1. 外层物品内层背包：同序号的物品聚集按照序号先后排列
2. 外层背包内层物品：在排好的序列上按序号逐一添元素
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint64_t> dp(target+1, 0);
        dp[0] = 1;

        // 错误
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = nums[i]; j <= target; j++){
        //         dp[j] += dp[j-nums[i]];
        //     }
        // }

        // 正确
        for(int j = 0; j <= target; j++){
            for(int i = 0; i < nums.size(); i++){
                if(j >= nums[i])
                    dp[j] += dp[j-nums[i]];
            }
        }

        return dp[target];
    }
};


int main() {

    return 0;
}
