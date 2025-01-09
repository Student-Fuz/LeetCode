#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/unique-paths-ii/description/

// Solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowCount = obstacleGrid.size();
        int colCount = (rowCount > 0) ? obstacleGrid[0].size() : 0; // 检查是否有行

        if(obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> matrix(rowCount, vector<int>(colCount));

        matrix[0][0] = 1;
        for(int i = 0; i < rowCount; i++){
            for(int j = 0; j < colCount; j++){
                if(obstacleGrid[i][j] == 1)
                    continue;
                if(i != 0){
                    matrix[i][j] += matrix[i-1][j];
                }
                if(j != 0){
                    matrix[i][j] += matrix[i][j-1];
                }
            }
        }

        return matrix[rowCount-1][colCount-1];
    }
};

int main(){

    Solution s;

    return 0;
}