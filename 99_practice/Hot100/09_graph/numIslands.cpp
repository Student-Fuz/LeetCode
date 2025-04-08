#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nums = 0;


        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    // 新岛
                    if( (i-1 < 0 || grid[i-1][j] <= '1')
                        && (i+1 == grid.size() || grid[i+1][j] <= '1') 
                        && (j-1 < 0 || grid[i][j-1] <= '1') 
                        && (j+1 == grid.size() || grid[i][j+1] <= '1')){
                            nums++;
                            grid[i][j] += nums;
                        }
                    // 旧岛
                    else{ 
                        if(!(i-1 < 0))
                            grid[i][j] = min(grid[i][j], grid[i-1][j]);
                        if(!(i+1 == grid.size()))
                            grid[i][j] = min(grid[i][j], grid[i+1][j]);
                        if(!(j-1 < 0))
                            grid[i][j] = min(grid[i][j], grid[i][j-1]);
                        if(!(j+1 == grid.size() < 0))
                            grid[i][j] = min(grid[i][j], grid[i][j+1]);
                    }
                }
            }
        }

    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}