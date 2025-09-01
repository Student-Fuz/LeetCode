#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m = mat.size(), n = mat[0].size();
        int x = 0, y = 0;
        bool updir = true; 
        while(!(x == m-1 && y == n-1)){
            if( 0 <= x && x < m && 0 <= y && y < n){
                res.push_back(mat[x][y]);
            }
            else if(updir){
                updir = false;
                if(x == -1){
                    y++;
                    if(y==n+1){
                        x++, y--;
                    }
                }else{
                    x++;
                }
            }
            else{
                updir = true;
                if(y == -1){
                    x++;
                    if(x==m+1){
                        x--, y++;
                    }
                }else{
                    y++;
                }
            }
            if(updir) x--, y++; 
            else x++, y--;
        }
        res.push_back(mat[x][y]);
        return res;
    }
};

int main() {

    return 0;
}