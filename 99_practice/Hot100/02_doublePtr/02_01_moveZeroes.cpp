#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/move-zeroes/description/?envType=study-plan-v2&envId=top-100-liked

// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow_ptr = 0;
        int fast_ptr = 0;

        for(; fast_ptr < nums.size(); fast_ptr++){
            if(nums[fast_ptr] != 0){
                nums[slow_ptr++] = nums[fast_ptr];
            }
        }

        for(;slow_ptr < nums.size(); slow_ptr++)
            nums[slow_ptr] = 0;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}