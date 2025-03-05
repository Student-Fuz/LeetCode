#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxLen = 1;
        vector<int> dp(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++){
            int maxLenBefore = 0;
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    maxLenBefore = max(maxLenBefore, dp[j]);
                }
            }
            dp[i] = maxLenBefore + 1;
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

// 贪心+二分 TODO

int main(){

    Solution s;

    vector<int> v = {10,9,2,5,3,7,101,18};
    s.lengthOfLIS(v);

    cout << "Hello, world!" << endl;

    return 0;
}