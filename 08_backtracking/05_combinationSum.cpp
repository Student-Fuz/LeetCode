#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>


using namespace std;

// 题目描述
// https://leetcode.cn/problems/combination-sum/

// Solution
// 优化TODO
class Solution {
private:
    unordered_set<string> result_set;
    vector<vector<int>> result;
    vector<int> combination;

void backtracking(vector<int>& candidates, int target, int sum){
    if(sum > target)
        return;
    if(sum == target){
        // 去重
        string result_s;
        vector<int> combination_copy = combination;
        sort(combination_copy.begin(), combination_copy.end());
        for(auto& int_c : combination_copy)
            result_s += to_string(int_c);
        if(result_set.find(result_s) == result_set.end()){
            result_set.insert(result_s);
            result.push_back(combination_copy);
        }  
        return;
    }
        
    for(int i = 0; i < candidates.size(); i++){
        combination.push_back(candidates[i]);
        backtracking(candidates, target, sum+candidates[i]);
        combination.pop_back();
    }

}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result_set.clear();
        result.clear();
        combination.clear();

        backtracking(candidates, target, 0);

        return result;
    }

};

int main(){

    Solution s;

    return 0;
}