#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/sort-matrix-by-diagonals/description/?envType=daily-question&envId=2025-08-28

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> result(grid);
        // if(grid.size() == 1) return result;
        vector<int> tmp;
        int x = grid.size()-1, y = 0;
        for(int i = 0; i < grid.size(); i++){
            while(x < grid.size()){
                tmp.push_back(grid[x][y]);
                x++, y++;
            }
            sort(tmp.begin(), tmp.end(), std::greater<int>());
            x--, y--;
            int j = tmp.size()-1;
            while(y >= 0){
                result[x][y] = tmp[j];
                x--, y--, j--;
            }
            y++;
            tmp.clear();
        }

        x = 0, y = 1;
        for(int i = 0; i < grid.size()-1; i++){
            while(y < grid.size()){
                tmp.push_back(grid[x][y]);
                x++, y++;
            }
            sort(tmp.begin(), tmp.end(), std::less<int>());
            x--, y--;
            int j = tmp.size()-1;
            while(x >= 0){
                result[x][y] = tmp[j];
                x--, y--, j--;
            }
            x++, y+=2;
            tmp.clear();
        }

        return result;
    }
};

// 标准答案


int main() {

    

    return 0;
}
