#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/first-missing-positive/?envType=study-plan-v2&envId=top-100-liked

// Solution
// 复习 TODO
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            // if(nums[i]-1 != i){
            //     if(nums[i] <= nums.size()){
            //         swap(nums[i], nums[nums[i]-1]);
            //     }
            // }

            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i]-1 != i && nums[nums[i]-1] != i){
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i]-1 != i){
                return i+1;
            }
        }

        return nums.size()+1;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}