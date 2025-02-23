#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/maximum-subarray/?envType=study-plan-v2&envId=top-100-liked

// m1: 暴力破解
// 时间复杂度O(N^2)
// Solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int maxVal = nums[0];
        int val = 0;

        for(int i = 0; i < nums.size(); i++){
            val = 0;
            for(int j = i; j < nums.size(); j++){
                val += nums[j];
                maxVal = max(maxVal, val);
            }
        }
        return maxVal;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int maxVal = nums[0];
        int preVal = nums[0];

        for(int i = 1; i < nums.size(); i++){
            preVal = max(preVal + nums[i], nums[i]);
            maxVal = max(preVal, maxVal);
        }
        return maxVal;
    }
};

// 更好写法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = nums[0];
        int preVal = 0;

        for(int i = 0; i < nums.size(); i++){
            preVal = max(preVal + nums[i], nums[i]);
            maxVal = max(preVal, maxVal);
        }
        return maxVal;
    }
};



int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}