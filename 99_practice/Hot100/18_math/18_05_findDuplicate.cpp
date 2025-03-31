#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/find-the-duplicate-number/description/?envType=study-plan-v2&envId=top-100-liked

// Solution
// 错误--一个数重复多次
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum - (1+nums.size()-1)*(nums.size()-1)/2;
    }
};

// 二分法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size()-1;
        int ans = 0;

        // 左闭右闭
        while(lower <= upper){
            int target = (lower+upper)/2;
            int lowerNum = 0;
    
            // 查找数组中有多少小于等于target的数
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= target)
                    lowerNum++;
                if(lowerNum > target)
                    break;
            }
            if(lowerNum > target){
                upper = target-1;
                ans = target;
            }
            else{
                lower = target+1;
                ans = target;
            }
        }
        return ans;
    }
};

// 二分法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size()-1;

        // 左闭右闭
        while(lower <= upper){
            int target = (lower+upper)/2;
            int lowerNum = 0;
    
            // 查找数组中有多少小于等于target的数
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= target)
                    lowerNum++;
                if(lowerNum > target)
                    break;
            }
            if(lowerNum > target){
                upper = target-1;
            }
            else{
                lower = target+1;
            }
        }
        // 注意思考：答案为什么是lower！！！
        return lower; // 循环结束时：lower == upper + 1
    }
};

// 位运算

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}