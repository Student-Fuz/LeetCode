#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/valid-sudoku/?envType=daily-question&envId=2025-09-01

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> st;
        for(int i = 0; i < 9; i++){
            st.clear();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && st.count(board[i][j])) return false;
                else st.insert(board[i][j]);
            }
        }

        for(int i = 0; i < 9; i++){
            st.clear();
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.' && st.count(board[j][i])) return false;
                else st.insert(board[j][i]);
            }
        }

        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                st.clear();
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[i+k][j+l] != '.' && st.count(board[i+k][j+l])) return false;
                        else st.insert(board[i+k][j+l]);
                    }
                }
            }
        }

        return true;

    }
};

int main() {

    return 0;
}