#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/largest-rectangle-in-histogram/description/

// 单调栈
// 找到每个高度左右的界限
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right(heights.size(), heights.size());
        vector<int> left(heights.size(), -1);

        stack<int> st;

        // 右边比自己小的边界
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // 左边比自己小的边界
        for(int i = heights.size()-1; i >= 0; i--){
            while(!st.empty() && heights[i] < heights[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }
        
        return maxArea;
    }
};

int main() {

    return 0;
}
