#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;

// 题目描述


// Solution
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 2)
            return 0;

        int maxHeight = height[0];
        int result = 0;

        int padding = 0;

        for(int i = 0, j = 1; j < height.size(); j++){
            // padding包含右壁
            padding += height[j];
            if(height[j] > maxHeight){
                if(maxHeight != 0){
                    result = result + maxHeight*(j-i-1) + height[j] - padding;
                }
                maxHeight = height[j];
                padding = 0;
            }
            else if(j == height.size()-1){

            }
        }
        return result;
    }
};

// Solution
// dynamic program
// 动态规划的核心体现在：
// 通过预计算 leftMax 和 rightMax，在后续的步骤中可以避免重复计算
// 时间复杂度O(N)
// 空间复杂度O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());

        int result = 0;

        int maxValue = 0;
        for(int i = 0; i < height.size(); i++){
            maxValue = max(height[i], maxValue);
            leftMax[i] = maxValue;
        }
        maxValue = 0;
        for(int i = height.size()-1; i >= 0; i--){
            maxValue = max(height[i], maxValue);
            rightMax[i] = maxValue;
        }

        for(int i = 0; i < height.size(); i++){
            result += min(leftMax[i], rightMax[i]) - height[i];
        }

        return result;
    }
};

// 单调栈
// 标答 常复习
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

// 双指针 TODO

int main(){

    Solution s;

    return 0;
}