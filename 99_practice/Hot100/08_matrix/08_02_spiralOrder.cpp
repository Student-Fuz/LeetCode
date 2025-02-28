#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/spiral-matrix/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int m = matrix.size();
        int n = matrix[0].size();

        int rowsVisted = 0;
        int colVisted = 0;

        int i = 0;
        int j = 0;
        while(rowsVisted != m && colVisted != colVisted){
            for(; j < n-colVisted; ++j){
                result.push_back(matrix[i][j]);
            }

            for(; ; ++i){
                result.push_back(matrix[i][j]);
            }

            for(; ; --j){
                result.push_back(matrix[i][j]);
            }

            for(; ; --i){
                result.push_back(matrix[i][j]);
            }
                
        }

        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}