#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/search-insert-position/?envType=study-plan-v2&envId=top-100-liked

// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

// 查找区间 左闭右闭
// lowerbound
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size()-1;
        int mid;

        while(begin <= end){
            mid = begin + (end - begin)/2;

            if(nums[mid] < target)
                begin = mid+1;
            else
                end = mid-1;
        }

        return begin;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}