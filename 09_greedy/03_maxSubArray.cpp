#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxVal = nums[0];
        for(auto& num : nums){
            pre = max(pre+num, num);
            maxVal = max(maxVal, pre);
        }
        return maxVal;
    }
};

int main() {

    return 0;
}