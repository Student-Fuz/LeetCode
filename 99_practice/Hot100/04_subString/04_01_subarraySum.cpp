#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/subarray-sum-equals-k/description/?envType=study-plan-v2&envId=top-100-liked

// Solution

// m1: 暴力法
// 时间复杂度 O(N^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum +=  nums[j];
                if(sum == k)
                    res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap;

        int res = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(nums[i] == k)
                res++;

            // sum_1 - sum_2 == k
            if(sumMap.find(sum - k) != sumMap.end())
                res += sumMap[sum - k];

            sumMap[sum]++; 
        }

        return res;
    }
};
    

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}