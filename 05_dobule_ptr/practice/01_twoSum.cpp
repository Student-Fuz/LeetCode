#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150
// 重点：有序数组

// Solution
// 暴力解法---超出时间限制
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++){
            for(int j = i+1; j < numbers.size(); j++){
                if(numbers[i] + numbers[j] == target)
                    return {i+1, j+1};
                else if(numbers[i] + numbers[j] > target)
                    break;
            }
        }

        return {};
    }
};
 
// 标准答案
// 利用好数组有序
// 空间复杂度O(1)
// 时间复杂度O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};

// 通法：适用于无序数组
// hash表---超出内存限制
// 空间复杂度O(N）
// 时间复杂度O(N）
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // key--value, val--index
        unordered_map<int, int> numbers_map;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers_map.find(target - numbers[i]) != numbers_map.end())
                return {numbers_map[target - numbers[i]]+1, i+1};
            numbers_map[numbers[i]] = i;
        }
        return {};
    }
};

int main(){

    Solution s;

    return 0;
}