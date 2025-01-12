#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/combination-sum-iii/

// Solution
// 回溯
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k, int n, int startIndex){
        if(path.size() == k){
            int sum = 0;
            for(auto& num : path)
                sum += num;
            if(sum == n)
                result.push_back(path);
            return;
        }
        for(int i = startIndex; i < 10; i++){
            path.push_back(i);
            backtracking(k, n, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};

// 回溯优化
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k, int n, int startIndex){
        if(path.size() == k){
            int sum = 0;
            for(auto& num : path)
                sum += num;
            if(sum == n)
                result.push_back(path);
            return;
        }
        for(int i = startIndex; i < 10; i++){
            path.push_back(i);
            backtracking(k, n, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};


int main(){

    Solution s;

    return 0;
}