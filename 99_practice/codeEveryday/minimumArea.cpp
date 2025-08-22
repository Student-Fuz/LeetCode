#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i/?envType=daily-question&envId=2025-08-22

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int x1 = grid.size(), y1 = grid[0].size(), x2 = -1, y2 = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        if(x1 != grid.size()) return (x2-x1+1)*(y2-y1+1);
        return 0;
    }
};

int main() {

    return 0;
}