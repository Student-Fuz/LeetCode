#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150

// Solution
// 暴力解法--超过时间限制
// 时间复杂度O(N^2)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = i; j < height.size(); j++){
                volume = max(volume, min(height[i], height[j]) * (j - i));
            }
        }

        return volume;
    }
};

//
class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume = 0;

        int low = 0, high = height.size()-1;
        // 从最长的宽开始
        while(high > low){
            
        }

        return volume;
    }
};

int main(){

    Solution s;

    return 0;
}