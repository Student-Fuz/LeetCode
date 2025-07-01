#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/



class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;

        sort(points.begin(), points.end());
        vector<vector<int>> intersections;
        intersections.push_back(points[0]);

        for(int i = 1; i < points.size(); i++){
            if(intersections.back()[0] <= points[i][0] && points[i][0] <= intersections.back()[1]){
                intersections.back()[0] = max(intersections.back()[0], points[i][0]);
                intersections.back()[1] = min(intersections.back()[1], points[i][1]);
            }else{
                intersections.push_back(points[i]);
            }
        }
        return intersections.size();
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;

        sort(points.begin(), points.end());
        vector<vector<int>> intersections;
        intersections.push_back(points[0]);

        for(int i = 1; i < points.size(); i++){
            int canShot = false;
            for(int j = 0; j < intersections.size(); j++){
                if(intersections[j][0] <= points[i][0] && points[i][0] <= intersections[j][1]){
                    intersections[j][0] = max(intersections[j][0], points[i][0]);
                    intersections[j][1] = min(intersections[j][1], points[i][1]);
                    canShot = true;
                    break;
                }
            }
            if(!canShot){
                intersections.push_back(points[i]);
            }
        }

        return intersections.size();
    }
};

int main() {

    

    return 0;
}
