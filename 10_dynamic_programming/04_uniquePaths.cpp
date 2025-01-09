#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/unique-paths/description/

// Solution
// 排列组合
class Solution {
public:
    int uniquePaths(int m, int n) {

        // paths = C(m+n-2) (m-1)
        long paths = 1;

        for(int x = n, y = 1; y < m; x++, y++){
            paths = paths * x / y;
        }

        return paths;

    }
};

// Solution
// 排列组合优化
class Solution {
public:
    int uniquePaths(int m, int n) {

        // paths = C(m+n-2) (m-1)
        long paths = 1;

        int min_mn = min(m, n);

        for(int x = m+n-min_mn, y = 1; y < min_mn; x++, y++){
            paths = paths * x / y;
        }

        return paths;

    }
};

// 动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {

        // 创建 m 行， n 列的矩阵
        // 法一：
        vector<vector<int>> matrix(m, std::vector<int>(n, 0));

        // 法二：
        //  std::vector<int> matrix[m];

        // // 初始化二维数组
        // for (int i = 0; i < m; i++) {
        //     matrix[i].resize(n);  
        // }

        matrix[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i != 0)
                    matrix[i][j] += matrix[i-1][j];
                if(j != 0)
                    matrix[i][j] += matrix[i][j-1];
            }
        }

        return matrix[m-1][n-1];

    }
};

int main(){

    Solution s;

    return 0;
}