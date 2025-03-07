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

// 位运算

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}