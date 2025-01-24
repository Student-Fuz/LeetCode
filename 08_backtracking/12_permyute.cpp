#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/permutations/

// Solution
class Solution {
private:
    void backtracking(vector<int>& nums, vector<int>& path, unordered_set<int>& numSet, vector<vector<int>>& result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(numSet.find(nums[i]) == numSet.end()){
                numSet.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, path, numSet, result);
                path.pop_back();
                numSet.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> numSet;
        vector<int> path;
        vector<vector<int>> result;

        // for(int i = 0; i < nums.size()+1; i++)
        //     backtracking(nums, 0, i, path, result);

        backtracking(nums, path, numSet, result);

        return result;
    }
};

// Solution
// 可用vector<bool>优化
class Solution {
private:
    void backtracking(vector<int>& nums, vector<int>& path, unordered_set<int>& numSet, vector<vector<int>>& result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(numSet.find(nums[i]) == numSet.end()){
                numSet.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, path, numSet, result);
                path.pop_back();
                numSet.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> numSet;
        vector<int> path;
        vector<vector<int>> result;

        // for(int i = 0; i < nums.size()+1; i++)
        //     backtracking(nums, 0, i, path, result);

        backtracking(nums, path, numSet, result);

        return result;
    }
};

// Solution
class Solution {
private:
    void backtracking(vector<int>& nums, int startIndex, int len, vector<int>& path, vector<vector<int>>& result){
        if(path.size() == len){
            result.push_back(path);
            return;
        }

        unordered_set<int> used;
        for(int i = 0; i < nums.size(); i++){
            if(used.find(nums[i]) == used.end()){
                used.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, startIndex+1, len, path, result);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> result;

        // for(int i = 0; i < nums.size()+1; i++)
        //     backtracking(nums, 0, i, path, result);

        backtracking(nums, 0, nums.size(), path, result);

        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}