#include <bits/stdc++.h>
using namespace std;

// 取l到r中间的最小值
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st_l(heights.size());
        vector<int> st_r(heights.size());
        st_l[0] = heights[0];
        st_r.back() = heights.back();

        for(int i = 1; i < heights.size(); i++){
            st_l[i] = min(st_l[i-1], heights[i]);
        }
        for(int i = heights.size()-2; i >= 0; i--){
            st_r[i] = min(st_r[i+1], heights[i]);
        }

        int maxArea = 0;
        for(int l = 0, r = heights.size()-1; l <= r;){
            int h = max(st_l[r], st_r[l]);
            int area = h * (r - l + 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {

    return 0;
}