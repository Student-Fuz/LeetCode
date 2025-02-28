#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/rotate-image/?envType=study-plan-v2&envId=top-100-liked

// Solution
// 原地解法
// 顺时针90° (i, j) ==> (j, n-1-i) (n-1-j ,i)==> (i, j)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < (n+1)/2; j++){
                int tmp = matrix[i][j];
                // 逆时针
                // matrix[i][j] = matrix[j][n - 1 - i];
                // matrix[j][n - 1 - i] = matrix[n - 1 - i][n - 1 - j];
                // matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i];
                // matrix[n - 1 - j][i] = tmp;

                // 顺时针
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;

            }
        }
    } 
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}