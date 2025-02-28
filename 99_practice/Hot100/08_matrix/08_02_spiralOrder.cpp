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

        // 左闭右开
        int left = 0;
        int right = n;
        int up = 0;
        int down = m;

        int i = 0;
        int j = 0;
        while(true){
            // 向右
            for(; j < right; ++j){
                result.push_back(matrix[i][j]);
            }
            up++;
            if(up == down || left == right)
                break;
            // 向下
            for(; i < down; ++i){
                result.push_back(matrix[i][j]);
            }
            right--;
            if(up == down || left == right)
                break;
            // 向左
            for(; j >= left; --j){
                result.push_back(matrix[i][j]);
            }
            down--;
            if(up == down || left == right)
                break;
            // 向上
            for(; i >= up; --i){
                result.push_back(matrix[i][j]);
            }
            left++;
            if(up == down || left == right)
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