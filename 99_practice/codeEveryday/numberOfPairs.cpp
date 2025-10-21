#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-i/?envType=daily-question&envId=2025-09-03

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt = 0;

        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                if(((points[j][0] <= points[i][0]) && (points[j][1] >= points[i][1])) ||
                    ((points[j][0] >= points[i][0]) && (points[j][1] <= points[i][1]))){
                    bool flag = false;
                    for(int k = 0; k < points.size(); k++){
                        if(k != i && k != j){
                            int x_can = points[k][0], y_can = points[k][1];
                            int x_min = min(points[i][0], points[j][0]), x_max = max(points[i][0], points[j][0]);
                            int y_min = min(points[i][1], points[j][1]), y_max = max(points[i][1], points[j][1]);
                            if(x_min <= x_can && x_can <= x_max && y_min <= y_can && y_can <= y_max){
                                flag = true;
                                break;
                            }
                        }
                    }
                    if(!flag) cnt++;
                }
            }
        }

        return cnt;
    }
};

int main() {

    return 0;
}