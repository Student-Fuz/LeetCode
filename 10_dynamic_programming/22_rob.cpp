#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> maxProfit(nums.size());
        maxProfit[0] = nums[0];
        maxProfit[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++){
            maxProfit[i] = max(maxProfit[i-1], maxProfit[i-2]+nums[i]);
        }

        return maxProfit[nums.size()-1];
    }
};

int main() {

    return 0;
}
