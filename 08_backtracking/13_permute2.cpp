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
// https://leetcode.cn/problems/permutations-ii/
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

// Solution
class Solution {
private:
    void backtracking(vector<int>& nums, vector<int> path, vector<vector<int>> result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            // 去重
            // 同一层值相同的元素只使用一次


            path.push_back(nums[i]);
            backtracking(nums, path, result);
            path.pop_back();

        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        // 排序
        sort(nums.begin(), nums.end());

        backtracking(nums, path, result);
 
        return result;
    }
};

// Solution
class Solution {
private:
    void backtracking(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            // 去重
            // 同一层值相同的元素只使用一次
            // if(used[i] == true)
            //     continue;
            // if (i != 0 && nums[i] == nums[i-1])
            //     continue;

            // 正确
            // 树层上去重
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            // 正确
            // 树枝上去重
            // if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == true)
            //     continue;

            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used, path, result);
                path.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        // 排序
        sort(nums.begin(), nums.end());

        backtracking(nums, used, path, result);
 
        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}