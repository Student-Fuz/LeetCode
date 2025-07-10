#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/trapping-rain-water/

// 第三遍 TODO
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;

        for(int i = 0; i < height.size(); i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int top = st.top();
                st.pop();
                if(st.empty())
                    break;
                int left = st.top();
                ans += (min(height[left], height[i]) - height[top])* (i-left-1);
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {

    return 0;
}
