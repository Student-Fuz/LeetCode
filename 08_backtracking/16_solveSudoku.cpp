#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sudoku-solver/

// 输入数独仅有一个解

// Solution
class Solution {
private:
    // 第j行，第k列
    bool backtracking(int cur_j, int cur_k, vector<vector<char>>& board){
        if(cur_j == 9)  // 递归终止条件，已遍历完所有行
            return true;

        // 如果到达当前行的最后一列，进入下一行
        int next_k = (cur_k + 1) % 9;
        int next_j = (next_k == 0) ? cur_j + 1 : cur_j;

        // 如果当前格子已填充数字，跳过
        if(board[cur_j][cur_k] != '.') {
            return backtracking(next_j, next_k, board);
        }

        // 尝试1到9的数字
        for(int curNum = 1; curNum <= 9; curNum++){
            bool continueFlag = false;

            // 同一行过滤 
            for(int k = 0; k < 9; k++){
                if(board[cur_j][k] == '0' + curNum){  // 将数字转换为字符 '0' + curNum
                    continueFlag = true;
                    break;
                }
            }
            if(continueFlag)
                continue;

            // 同一列过滤
            for(int j = 0; j < 9; j++){
                if(board[j][cur_k] == '0' + curNum){  // 将数字转换为字符 '0' + curNum
                    continueFlag = true;
                    break;
                }
            }

            if(continueFlag)
                continue;

            // 九宫格过滤
            int boxStartRow = (cur_j / 3) * 3;
            int boxStartCol = (cur_k / 3) * 3;

            for(int i = boxStartRow; i < boxStartRow + 3; i++){
                for(int j = boxStartCol; j < boxStartCol + 3; j++){
                    if(board[i][j] == '0' + curNum){
                        continueFlag = true;
                        break;
                    }
                }
                if(continueFlag)
                    break;
            }

            if(continueFlag)
                continue;

            // 填充数字并继续递归
            board[cur_j][cur_k] = '0' + curNum;

            // 如果当前填充成功，继续递归，尝试下一个位置
            if(backtracking(next_j, next_k, board)) {
                return true;
            }

            // 恢复
            board[cur_j][cur_k] = '.';
        }

        return false;  // 无解时返回 false
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(0, 0, board);
    }
};


int main(){

    Solution solution;

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };


    solution.solveSudoku(board);

    // 打印解答
    for (auto& row : board) {
        for (auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}