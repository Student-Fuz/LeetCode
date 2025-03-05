#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            if(nums.size() == 0)
                return false;
            int sumVal = 0;
    
            for(int i = 0; i < nums.size(); i++){
                sumVal += nums[i];
            }
    
            int target = sumVal/2;
    
            // 奇数
            if(sumVal - target != target)
                return false;
    
            vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, false));
            dp[0][0] = true;
            if(nums[0] < target)
                dp[0][nums[0]] = true;
            if(nums[0] == target)
                return true;
    
            for(int i = 1; i < nums.size(); i++){
                dp[i][0] = true;
                for(int j = 0; j <= target; j++){
                    if(dp[i-1][j] == true){
                        dp[i][j] = true;
                        int sum = j+nums[i];
                        if(sum <= target){
                            dp[i][sum] = true;
                            if(sum == target)
                                return true;
                        }
                    }
                }
            }
            
            return false;
        }
    };

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}