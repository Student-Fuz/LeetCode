#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// link: https://leetcode.cn/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 哈希表--统计解法 时间复杂度O(n),空间复杂度O(n)
        std:: unordered_map<int, int> freq_map;
        for(auto num : nums){
            if(freq_map.find(num) != freq_map.end())
                freq_map[num] += 1;
            else
                freq_map[num] = 1;
        }
        for(auto& [num, freq] : freq_map)
            if(freq > nums.size()/2)
                return num;
        return 0;
    }
};

// TODO 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 接口排序法 时间复杂度O(nlogn) 自带--空间复杂度O(logn), 堆排序--空间复杂度O(1)
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// Boyer-Moore 投票算法 时间最优、空间最优
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count = 0;
        for(auto num: nums){
            if(num == candidate)
                count++;
            else if(--count < 0){
                candidate = num;
                count = 1;
            }
        }
    }
};

int main(){

    Solution s;

    return 0;
}