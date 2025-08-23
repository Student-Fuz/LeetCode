#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSquare(vector<vector<int>>& m, int x, int y, int l){
        if(x+l-1 >= m.size() || y+l-1 >= m[0].size()) return false;
        for(int i = x; i <= x+l-1; i++){
            for(int j = y; j <= y+l-1; j++){
                if(m[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int l = 1;
        int cnt = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 1){
                    q.push({i, j});
                    cnt++;
                }
                    
            }
        }
        l = 2;
        for(; l <= matrix.size(); l++){
            int size = q.size();
            if(size == 0) break;
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(isSquare(matrix, x, y, l)){
                    q.push({x, y});
                    cnt++;
                };
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}