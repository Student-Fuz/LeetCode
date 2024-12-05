#include <iostream>
#include <string>
#include <array>
#include <vector>

// link: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

// 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
// 返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
// 然后返回 nums 中唯一元素的个数。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(slow < 1 || nums[slow - 1] != nums[fast])
                nums[slow++] = nums[fast];
        }
        return slow;
    }
};


int main(){

    Solution s;

    return 0;
}