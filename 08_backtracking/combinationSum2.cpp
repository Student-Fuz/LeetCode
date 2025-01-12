#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/combination-sum-ii/

// Solution
class Solution {
private:
    vector<vector<int>> result;
    vector<int> combination;
    
    void backtracking(vector<int>& candidates, int startIndex, int target, int sum){
        if(sum > target)
            return;
        if(sum == target){
            // 去重
            result.push_back(combination);
            return;
        }

        for(int i = startIndex; i < candidates.size(); i++){
            combination.push_back(candidates[i]);
            backtracking(candidates, i+1, target, sum+candidates[i]);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        combination.clear();

        backtracking(candidates, 0, target, 0);

        return result;
    }
};

int main(){

    Solution s;

    return 0;
}