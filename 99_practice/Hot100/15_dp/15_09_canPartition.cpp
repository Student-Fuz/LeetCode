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
        int sumVal = 0;

        for(int i = 0; i < nums.size(); i++){
            sumVal += nums[i];
        }

        
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}