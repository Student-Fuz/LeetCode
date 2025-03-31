#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/generate-parentheses/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
private:
    bool search(vector<vector<char>>& board, 
                vector<vector<bool>>& used, 
                string word, int x, int y, int target){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;

        if(used[x][y] == true)
            return false;

        bool flag1, flag2, flag3, flag4;

        if(board[x][y] == word[target]){
            target += 1;
            used[x][y] = true;
            if(target == word.size()) return true;
            flag1 = search(board, used, word, x-1, y, target);
            flag2 = search(board, used, word, x+1, y, target);
            flag3 = search(board, used, word, x, y-1, target);
            flag4 = search(board, used, word, x, y+1, target);
        }
        else{
            return false;
        } 

        used[x][y] = false;
        return flag1 | flag2 | flag3 | flag4;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(search(board, used, word, i, j, 0))
                    return true;
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