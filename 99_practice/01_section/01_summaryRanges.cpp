#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述


// Solution
// bad code repeated operations
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        // 双指针
        for(int slow = 0, fast = 0; fast < nums.size(); fast++){
            if(fast-1 >= 0 && nums[fast] != nums[fast-1] + 1){
                if(slow == fast-1)
                    result.push_back(to_string(nums[slow]));
                else
                    result.push_back(to_string(nums[slow]) + "->" + to_string(nums[fast-1]));
                slow = fast;
            }
            if(fast == nums.size()-1){
                if(fast-1 >= 0){
                    if(slow == fast)
                        result.push_back(to_string(nums[slow]));
                    else
                        result.push_back(to_string(nums[slow]) + "->" + to_string(nums[fast]));
                }
                else
                    result.push_back(to_string(nums[slow]));
            }
        }
        return result;
    }
};

// leetcode 官方题解
// 无特判
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ret.push_back(move(temp));
        }
        return ret;
    }
};


int main(){

    Solution s;

    return 0;
}