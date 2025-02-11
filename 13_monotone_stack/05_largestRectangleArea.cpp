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
// https://leetcode.cn/problems/largest-rectangle-in-histogram/

// 思路：找右侧第一个比自己小的数

// Solution
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        if(heights.size() == 0)
            return 0;
        st.push(0);

        for(int i = 1; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                maxArea = max(maxArea, (i - st.top()) * heights[st.top()]);
                st.pop();
            }
            st.push(i);
        }

        // 栈中剩余元素：右侧无比自己小的数
        while(!st.empty()){
            maxArea = max(maxArea, ((int)heights.size() - st.top()) * heights[st.top()]);
            st.pop();
        }

        return maxArea;
    }
};


// 思路：右侧边界，左侧边界
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), heights.size());
        int maxArea = 0;

        if(heights.size() == 0)
            return 0;
        st.push(0);

        // 右侧边界
        for(int i = 1; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        st.push(heights.size()-1);
        // 左侧边界
        for(int i = heights.size()-2; i >= 0; i--){
            while(!st.empty() && heights[i] < heights[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

    
        // 最大值比较
        for(int i = 0; i <heights.size(); i++)
            maxArea = max(maxArea, (right[i] - left[i] - 1) * heights[i]);

        return maxArea;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}