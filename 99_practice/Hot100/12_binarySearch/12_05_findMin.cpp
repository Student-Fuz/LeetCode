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
// try1
// fail in case nums = [11,13,15,17]
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = nums.size() - 1;
        int mid = (l+r)/2;
        while(l < r){
            mid = (l+r)/2;
            if(nums[0] <= nums[mid]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return nums[l];
    }
};

// Solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = nums.size() - 1;
        int mid = (l+r)/2;
        while(l < r){
            mid = (l+r)/2;
            if(nums[r] > nums[mid]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

int main(){

    cout << "Hello, world!" << endl;

    return 0;
}