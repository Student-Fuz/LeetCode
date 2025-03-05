#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/maximum-product-subarray/description/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        // first--positive second--negative
        vector<pair<int, int>> dp(nums.size(), {0, 0});
        int maxPro;
        if(nums[0] > 0){
            dp[0].first = nums[0];
            maxPro = nums[0];
        }
        else{
            dp[0].second = nums[0];
            maxPro = nums[0];
        }
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > 0){
                dp[i].first = max(nums[i], nums[i] * dp[i-1].first);
                dp[i].second = nums[i] * dp[i-1].second;
            }
            else{
                dp[i].first = max(dp[i-1].second, nums[i] * dp[i-1].second);
                dp[i].second = min(nums[i], nums[i] * dp[i-1].first);
            }
            maxPro = max(maxPro, dp[i].first);
        }

        return maxPro;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}