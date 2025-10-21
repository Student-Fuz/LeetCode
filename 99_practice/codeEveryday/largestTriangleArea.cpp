#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/largest-triangle-area/description/?envType=daily-question&envId=2025-09-27

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        if(points.size() < 3) return 0;
        for(int i = 0; i < points.size()-2; i++){
            for(int j = i+1; j < points.size()-1; j++){
                for(int k = j+1; k < points.size(); k++){
                    double area = 0.5*abs(points[i][0]*points[j][1] + points[j][0]*points[k][1] + points[k][0]*points[i][1]
                    - points[i][0]*points[k][1] - points[j][0]*points[i][1] - points[k][0]*points[j][1]);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main() {

    return 0;
}