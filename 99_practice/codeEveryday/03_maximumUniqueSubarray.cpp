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

// 哈希表+前缀和
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> sums(nums.size()+1, 0);
        // key--val, val--index
        unordered_map<int, int> map;
        int maxScore = 0;
        int begin = 0;

        for(int i = 0; i < nums.size(); i++){
            sums[i+1] = sums[i] + nums[i];
            begin = max(begin, map[nums[i]]);
            maxScore = max(maxScore, sums[i+1] - sums[begin]);
            map[nums[i]] = i+1;
        }

        return maxScore;
    }
};

// 滑动窗口--新写法TODO

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

// 哈希表+前缀和 TODO--这版不好
// 前缀和最好定义为vector<n+1>
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> sums(nums.size(), 0);
        sums[0] = nums[0];
        // key--val, val--index
        unordered_map<int, int> map;
        map[nums[0]] = 0;
        int maxScore = sums[0];
        int begin = 0;

        for(int i = 1; i < nums.size(); i++){
            sums[i] = sums[i-1] + nums[i];
            if(map.count(nums[i]) != 0){
                begin = max(begin, map[nums[i]]+1);
            }
            int currentSum;
            if (begin == 0) {
                currentSum = sums[i];
            } else {
                currentSum = sums[i] - sums[begin - 1];
            }

            maxScore = max(maxScore, currentSum);
            map[nums[i]] = i;
           
        }

        return maxScore;
    }
};


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

