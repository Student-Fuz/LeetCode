#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/length-of-longest-v-shaped-diagonal-segment/description/?envType=daily-question&envId=2025-08-27

vector<vector<int>> dirs = {
    {-1,-1},
    {-1, 1},
    {1, -1},
    {1, 1}
};

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<int> last, vector<int> dir, bool turned, int len1, int len2, int& maxLen){
        int x = last[0] + dir[0];
        int y = last[1] + dir[1];
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 1){
            // if(len2 > 0){
            //     maxLen = max(maxLen, len1+len2);
            // }
            maxLen = max(maxLen, len1+len2);
            return;
        }

        if((grid[last[0]][last[1]] < 2  && grid[x][y] == 2) || 
            (grid[last[0]][last[1]] == 2  && grid[x][y] == 0)){
            if(turned) dfs(grid, {x, y}, dir, turned, len1, len2+1, maxLen);
            else dfs(grid, {x, y}, dir, turned, len1+1, len2, maxLen);
        }
        else{
            maxLen = max(maxLen, len1+len2);
            return;
        }


        if(!turned){
            // vector<int> turned_dir1 = {-dir[0], dir[1]};
            // dfs(grid, {x, y}, turned_dir1, true, len1+1, len2, maxLen);

            // vector<int> turned_dir2 = {dir[0], -dir[1]};
            // dfs(grid, {x, y}, turned_dir2, true, len1+1, len2, maxLen);
            
            // 顺时针
            vector<int> turned_dir;
            if(dir[0] + dir[1] == 0) turned_dir = {-dir[0], dir[1]};
            else turned_dir = {dir[0], -dir[1]};
            dfs(grid, {x, y}, turned_dir, true, len1+1, len2, maxLen);
        }
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int maxLen = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < dirs.size(); k++){
                        dfs(grid, {i, j}, dirs[k], false, 1, 0, maxLen);
                    }
                }
            }
        }

        return maxLen;
    }
};

int main() {

    return 0;
}