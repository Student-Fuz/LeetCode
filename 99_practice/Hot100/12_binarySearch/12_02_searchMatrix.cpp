#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> first_col;

        for(int i = 0; i < matrix.size(); i++){
            first_col.push_back(matrix[i][0]);
        }

        auto it = upper_bound(first_col.begin(), first_col.end(), target);

        int row_index =  distance(first_col.begin(), it);

        row_index--;

        if(row_index == -1)
            return false;
        
        it = lower_bound(matrix[row_index].begin(), matrix[row_index].end(), target);

        int col_index = distance(matrix[row_index].begin(), it);

        if(col_index == matrix[row_index].size())
            return false;

        if(matrix[row_index][col_index] == target)
            return true;
        else
            return false;

    }
};

int main(){

    Solution s;
                    // 0  1  2  3  4  5  6  7  8
    vector<int> vec = {1, 2, 4, 5, 5, 6, 6, 7, 8};

    // target 5 ---> 3
    // target 6 ---> 3
    // 5
    auto it = lower_bound(vec.begin(), vec.end(), 6);
    int row_index =  distance(vec.begin(), it);

    cout << row_index << endl;

    // 7
    auto it_1 = upper_bound(vec.begin(), vec.end(), 6);
    int row_index_1 =  distance(vec.begin(), it_1);

    cout << row_index_1 << endl;

    // vector<vector<int>> vec = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    // s.searchMatrix(vec, 3);

    cout << "Hello, world!" << endl;

    return 0;
}