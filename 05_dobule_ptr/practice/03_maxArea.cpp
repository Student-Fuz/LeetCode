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

// 双指针
// 数学证明 TODO
// https://leetcode.cn/problems/container-with-most-water/solutions/207215/sheng-zui-duo-shui-de-rong-qi-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume = 0;

        int front = 0, back = height.size()-1;
        int lower = 0;
        // 从最长的宽开始
        while(back > front){
            lower = min(height[front], height[back]);
            volume = max(lower * (back - front), volume);
            if(lower == height[front])
                front++;
            else // lower == back
                back--;
        }

        return volume;
    }
};

int main(){

    Solution s;

    return 0;
}