#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22

// 第一反应--类似滑动窗口
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int begin = 0;
        int end = 0;
        // key--value, val--index 
        unordered_map<int, int> map;
        int sum = 0;
        int maxScore = 0;
        for(; end < nums.size(); end++){
            if(map.count(nums[end]) == 0){
                map[nums[end]] = end;
                sum += nums[end];
                maxScore = max(maxScore, sum);
            }
            else{
                int newBegin = map[nums[end]]+1;
                for(int i = begin; i < newBegin; i++){
                    sum -= nums[i];
                    map.erase(nums[i]);
                }
                begin = newBegin;
                map[nums[end]] = end;
                sum += nums[end];
            }
        }
        return maxScore;
    }
};

// 哈希表+前缀和 TODO



// 滑动窗口

// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int maxScore = 0;
//         int sum = nums[0];
//         int begin = 0;
//         int end = 0;

//         for(end = 1; end < nums.size(); end++){
//             end
//         }
//     }
// };

int main() {

    return 0;
}

