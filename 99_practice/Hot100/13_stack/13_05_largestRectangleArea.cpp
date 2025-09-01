#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> l(heights.size(), -1);
        vector<int> r(heights.size(), heights.size());
        stack<int> st;

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(int i = heights.size()-1; i >= 0; i--){
            while(!st.empty() && heights[i] < heights[st.top()]){
                l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            maxArea = max(maxArea, (r[i]-l[i]-1)*heights[i]);
        }

        return maxArea;
    }
};

// 算法不正确
// 取l到r中间的最小值
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        multiset<int> set;
        for(const auto& h : heights){
            set.insert(h);
        }

        int maxArea = 0;
        for(int l = 0, r = heights.size()-1; l <= r;){
            int h = *set.begin();
            int area = h * (r - l + 1);
            maxArea = max(maxArea, area);
            if(heights[l] < heights[r]){   
                auto it = set.find(heights[l]);
                if (it != set.end()) set.erase(it);
                l++;
            }
            else{
                auto it = set.find(heights[r]);
                if (it != set.end()) set.erase(it);
                r--;
            }
        }

        return maxArea;
    }
};

int main() {

    return 0;
}