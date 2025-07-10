#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
// 自写
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 0) return -1;

        int l = 0, r = nums.size() - 1;
        int mid = (l + r)/2;
        while(l <= r){
            mid = (l + r)/2;
            if(nums[mid] == target) return mid;
            if(nums[0] <= nums[mid]){
                if(nums[0] <= target && target < nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[n-1]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }

        }

        return -1;
    }
};















// 标准答案
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        // 左闭右闭
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};


    

int main(){

    cout << "Hello, world!" << endl;

    return 0;
}