#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rowSet;
        unordered_set<int> colSet;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }

        for(const int& row : rowSet){
            for(int j = 0; j < matrix[row].size(); j++)
                matrix[row][j] = 0;
        }

        for(const int& col : colSet){
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][col] = 0;
        }
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}