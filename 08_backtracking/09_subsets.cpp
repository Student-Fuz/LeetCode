#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/subsets/

// Solution
class Solution {
private:
    void backtracking(vector<int>& nums, int startIndex, int len, vector<int>& subset, vector<vector<int>>& result){
        if(subset.size() == len){
            result.push_back(subset);
            return;
        }

        if(subset.size() > len)
            return;


        for(int i = startIndex; i < nums.size(); i++){
            subset.push_back(nums[i]);
            backtracking(nums, i+1, len, subset, result);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        for(int i = 0; i < nums.size()+1; i++){
            backtracking(nums, 0, i, subset, result);
        }

        return result;
    }
};

int main(){

    Solution s;

    return 0;
}