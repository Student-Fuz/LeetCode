#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<int> st;
        for(int i = 0; i < height.size(); i++){
            if(st.empty() || height[i] <= height[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && height[i] > height[st.top()]){
                    int bottom = height[st.top()];
                    st.pop();
                    if(st.empty())
                        break;
                    int left = st.top();
                    result += (min(height[i], height[left]) - bottom)*(i-left-1);
                }
                st.push(i);
            }
        }
        return result;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<int> st;
        for(int i = 0; i < height.size(); i++){
            if(st.empty() || height[i] < height[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && height[i] >= height[st.top()]){
                    int bottom = height[st.top()];
                    st.pop();
                    if(st.empty())
                        break;
                    int left = st.top();
                    result += (min(height[i], height[left]) - bottom)*(i-left-1);
                }
                st.push(i);
            }
        }
        return result;
    }
};

int main() {

    return 0;
}