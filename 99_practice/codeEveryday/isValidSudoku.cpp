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
                st.insert(board[i][j]);
            }
            if(st.size() != 9) return false;
        }

        for(int i = 0; i < 9; i++){
            st.clear();
            for(int j = 0; j < 9; j++){
                st.insert(board[j][i]);
            }
            if(st.size() != 9) return false;
        }
        st.clear();
        
    }
};

int main() {

    return 0;
}