#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/n-queens/

// Solution
// 未去对角
class Solution {
private:
    void backtracking(int n, vector<bool>& used, vector<string>& path, vector<vector<string>>& result){
        if(path.size() == n){
            result.push_back(path);
            return;
        }

        for(int i = 0; i < n; i++){
            if(used[i] == true)
                continue;

            used[i] = true;
            path.push_back(constructLine(n, i));
            backtracking(n, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }

    string constructLine(int n, int pos){
        string result;
        for(int i = 0; i < pos; i++)
            result.push_back('.');

        result.push_back('Q');

        for(int i = 0; i < n-pos-1; i++)
            result.push_back('.');

        return result;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> path;
        vector<bool> used(n, false);

        backtracking(n, used, path, result);

        return result;
        
    }
};

// Solution
class Solution {
private:
    void backtracking(int n, vector<vector<bool>>& used, vector<string>& path, vector<vector<string>>& result){
        if(path.size() == n){
            result.push_back(path);
            return;
        }

        // 第path.size()行，i列
        for(int i = 0; i < n; i++){
            bool continueFlag = false; 
            for(int j = 0; j < path.size(); j++){
                // 判断列上是否有元素
                if(used[j][i] == true){
                    continueFlag = true;
                    break;
                }
                int dis = path.size()-j;
                // 判断左上对角
                if(i - abs(dis) >= 0 && used[j][i - (path.size()-j)] == true){
                    continueFlag = true;
                    break;
                }
                // 判断右上对角
                if(i + abs(dis) < n && used[j][i+(path.size()-j)] == true){
                    continueFlag = true;
                    break;
                }
            }
            if(continueFlag)
                continue;

            used[path.size()][i] = true;
            path.push_back(constructLine(n, i));
            backtracking(n, used, path, result);
            path.pop_back();
            used[path.size()][i] = false;
        }
    }

    string constructLine(int n, int pos){
        string result;
        for(int i = 0; i < pos; i++)
            result.push_back('.');

        result.push_back('Q');

        for(int i = 0; i < n-pos-1; i++)
            result.push_back('.');

        return result;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> path;
        vector<vector<bool>> used(n, vector<bool>(n, false));

        backtracking(n, used, path, result);

        return result;
        
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;
    

    return 0;
}