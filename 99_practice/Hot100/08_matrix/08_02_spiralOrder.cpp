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
// 口口口口
// 口口口口
// 口口口口
// 口口口口

// 1 1 1 1
// 4 5 5 2
// 4 7 6 2
// 3 3 3 2

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int m = matrix.size();
        int n = matrix[0].size();

        // 左闭右闭
        int left = 0;
        int right = n-1;
        int up = 0;
        int down = m-1;

        int i = 0; 
        int j = -1;
        while(true){
            // 向右
            for(j++; j <= right; ++j){
                result.push_back(matrix[i][j]);
            }
            up++;
            j--;
            if(up > down || left > right)
                break;
            // 向下
            for(i++; i <= down; ++i){
                result.push_back(matrix[i][j]);
            }
            right--;
            i--;
            if(up > down || left > right)
                break;
            // 向左
            for(j--; j >= left; --j){
                result.push_back(matrix[i][j]);
            }
            down--;
            j++;
            if(up > down || left > right)
                break;
            // 向上
            for(i--; i >= up; --i){
                result.push_back(matrix[i][j]);
            }
            left++;
            i++;
            if(up > down || left > right)
                break;   
        }

        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}