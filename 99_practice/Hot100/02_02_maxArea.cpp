#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 左闭右闭
        int begin = 0;
        int end = height.size() - 1;
        int lower = min(height[begin], height[end]);
        int maxArea = lower * (end - begin);

        while(begin <= end){
            lower = min(height[begin], height[end]);
            maxArea = max(maxArea, lower * (end - begin));

            if(lower == height[begin])
                begin++;
            else
                end--;
        }

        return maxArea;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}