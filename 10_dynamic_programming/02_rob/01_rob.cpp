#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/house-robber/

// Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];

        vector<int> maxProfit(nums.size(), 0);

        maxProfit[0] = nums[0];
        maxProfit[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++)
            maxProfit[i] = max(maxProfit[i-2] + nums[i], maxProfit[i-1]);

        return maxProfit[nums.size()-1];
    }
};
int main(){

    Solution s;

    return 0;
}