#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/subsets-ii/

// 树层去重 与 树枝去重


// Solution
class Solution {
private:
    void backtracking(vector<int>& nums, int startIndex, int len, vector<unordered_set<int>>& layers, vector<int>& subset, vector<vector<int>>& result){
        if(subset.size() > len)
            return;
        if(subset.size() == len){
            result.push_back(subset);
            return;
        }

        for(int i = startIndex; i < nums.size(); i++){
            // 树层去重
            // 如果这层已经取了相同的元素了，则不再取相同元素
            if(layers[len].find(nums[i]) == layers[len].end()){
                layers[len].insert(nums[i]);
                subset.push_back(nums[i]);
                backtracking(nums, i+1, len, layers, subset, result);
                subset.pop_back();
            }
        }

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        vector<unordered_set<int>> layers(nums.size());

        for(int i = 0; i < nums.size()+1; i++){
             backtracking(nums, 0, i, layers, subset, result);
        }

        return result;
    }
};

int main(){

    Solution s;

    return 0;
}