#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/pascals-triangle/description/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for(int row = 0; row < numRows; row++){
            result.emplace_back();
            for(int i = 0; i < row+1; i++){
                if(row-1 > 0 && i != 0 && i != row){
                    int num = result[row-1][i-1]+result[row-1][i];
                    result.back().push_back(num);
                }
                else
                result.back().push_back(1);
            }
        }

        return result;
    }
};

// 动态规划

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}