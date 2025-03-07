#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/minimum-path-sum/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i-1 >= 0 && j-1 >= 0){
                    grid[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j];
                }
                // 无上
                else if(i-1 < 0 && j-1 >= 0){
                    grid[i][j] += grid[i][j-1];
                }
                // 无左
                else if(j-1 < 0 && i-1 >= 0){
                    grid[i][j] += grid[i-1][j];
                }  
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}