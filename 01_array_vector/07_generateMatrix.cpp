#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int x = 0, y = 0;

        // 左闭右开
        int l = 0, r = n; 
        int u = 0, d = n;

        int val = 1;

        while(val != n*n + 1){
            // 向右
            while(y < r){
                mat[x][y++] = val++;
            }
            y--;
            x++;
            u++;
            // 向下
            while(x < d){
                mat[x++][y] = val++;
            }
            x--;
            y--;
            r--;
            // 向左
            while(y >= l){
                mat[x][y--] = val++;
            }
            y++;
            x--;
            d--;
            // 向上
            while(x >= u){
                mat[x--][y] = val++;
            }
            x++;
            y++;
            l++;
        }
        return mat;
    }
};


int main(){ 


    int val = 0;

    cout << val++ << endl;

    return 0;
}