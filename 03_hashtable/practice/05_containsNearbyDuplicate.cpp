#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

// Solution
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // key--value, val--last_index
        unordered_map<int, int> indices_map; 

        for(int i = 0; i < nums.size(); i++){
            if(indices_map.find(nums[i]) != indices_map.end())
                if(indices_map[nums[i]] >= i-k)
                    return true;
                else
                    indices_map[nums[i]] = i;
            else    
                indices_map[nums[i]] = i;
        }

        return false;
    }
};

// 简洁版
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // key--value, val--last_index
        unordered_map<int, int> indices_map; 

        for(int i = 0; i < nums.size(); i++){
            if(indices_map.find(nums[i]) != indices_map.end())
                if(indices_map[nums[i]] >= i-k)
                    return true;
            indices_map[nums[i]] = i;
        }

        return false;
    }
};

int main(){

    Solution s;

    return 0;
}