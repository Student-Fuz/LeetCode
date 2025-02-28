#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/search-a-2d-matrix-ii/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i].size() > 0 && matrix[i][0] > target)
                break;
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] > target)
                    break;
                else if(matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};

// 二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i].size() > 0 && matrix[i][0] > target)
                break;
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(it != matrix[i].end() && *it == target)
                return true;
        }
        return false;
    }
};

// 二分查找Ⅱ
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        if(matrix[0].size() == 0)
            return false;
        int len = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i].size() > 0 && matrix[i][0] > target)
                break;
            auto it = lower_bound(matrix[i].begin(), matrix[i].begin()+len, target);
            len = distance(matrix[i].begin(), it);
            if(it != matrix[i].end() && *it == target)
                return true;
        }
        return false;
    }
};

// Z字查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            }
            else {
                ++x;
            }
        }
        return false;
    }
};

// Z字查找 1-1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        auto it = lower_bound(matrix[0].begin(), matrix[0].end(), target);
        y = distance(matrix[0].begin(), it);
        if(y == matrix[0].size())
            --y;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            }
            else {
                ++x;
            }
        }
        return false;
    }
};

// Z字查找Ⅱ
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = m - 1, y = 0;
        while (x >= 0 && y < n) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --x;
            }
            else {
                ++y;
            }
        }
        return false;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}