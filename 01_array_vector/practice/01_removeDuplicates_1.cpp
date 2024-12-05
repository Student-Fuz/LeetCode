#include <iostream>
#include <string>
#include <array>
#include <vector>

// link: https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/submissions/584903700/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

// 进阶：删除非有序序列数组的重复项，如何解决

// 更优 TODO
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 双指针法
        int slow = 0;
        for(int medium = 0, fast = 0; fast < nums.size(); fast++){
            if(fast == nums.size()-1){
                if(nums[fast] != nums[medium]){
                    if(fast - medium > 1){
                        int value = nums[medium];
                        nums[slow++] = value;
                        nums[slow++] = value;
                    }
                    else{
                        int value = nums[medium];
                        nums[slow++] = value;
                    }
                    int value = nums[fast];
                    nums[slow++] = value;
                }
                else{
                    if(fast==medium){
                        int value = nums[medium];
                        nums[slow++] = value;
                    }
                    else{
                        int value = nums[medium];
                        nums[slow++] = value;
                        nums[slow++] = value;
                    }
                }
                break;
            }
            if(nums[fast] != nums[medium]){
                if(fast - medium > 1){
                    int value = nums[medium];
                    nums[slow++] = value;
                    nums[slow++] = value;
                }
                else{
                    int value = nums[medium];
                    nums[slow++] = value;
                }
                medium = fast;
            }
        }
        return slow;
    }
};

// 标准答案
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 双指针法
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(slow < 2 || nums[slow-2] != nums[fast])
                nums[slow++] = nums[fast];
        }
        return slow;
    }

    int process(vector<int>& nums, int k){
        // 双指针法
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            // 当前存储数据小于长度k时，直接照抄nums[fast]
            if(slow < k || nums[slow-k] != nums[fast])
                nums[slow++] = nums[fast];
        }
        return slow;
    }
};


int main(){

    Solution s;

    return 0;
}