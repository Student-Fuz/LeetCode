#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/non-decreasing-subsequences/

// Solution
// 连续非递减子序列
class Solution {
private:
    void backtracking(const vector<int>& nums, int startIndex, vector<int>& sub, vector<vector<int>>& result){
       if(sub.size() > 1)
            result.push_back(sub);

        if(startIndex == nums.size())
            return;

        if(sub.size() < 2 || nums[startIndex] >= nums[startIndex-1]){
            sub.push_back(nums[startIndex]);
            backtracking(nums, startIndex+1, sub, result);
            sub.pop_back();
        }

    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;

        for(int i = 0; i < nums.size(); i++)
            backtracking(nums, i, sub, result);

        return result;
    }
};

// Solution
// 非递减子序列 （低效版）
class Solution {
private:
    void backtracking(const vector<int>& nums, int startIndex, vector<int>& sub, vector<vector<int>>& result){
       if(sub.size() > 1){
            // 去重
            bool repeat_flag = false;
            for(int i = 0; i < result.size(); i++){
                if(result[i].size() == sub.size()){
                    repeat_flag = true;
                    for(int j = 0; j < sub.size(); j++)
                        if(result[i][j] != sub[j]){
                            repeat_flag = false;
                            break;
                        }
                    if(repeat_flag == true)
                        break;
                }
            }
            if(!repeat_flag)
                result.push_back(sub);
            else
                return;
       }
            

        if(startIndex == nums.size())
            return;

        for(int i = startIndex; i < nums.size(); i++){
            if(sub.size() < 1 || nums[i] >= sub.back()){
                sub.push_back(nums[i]);
                backtracking(nums, i+1, sub, result);
                sub.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;

        backtracking(nums, 0, sub, result);

        return result;
    }
};

// Solution
// 非递减子序列
class Solution {
private:
    void backtracking(const vector<int>& nums, int startIndex, vector<int>& sub, vector<vector<int>>& result){
        if(sub.size() > 1)
            result.push_back(sub);
            
        if(startIndex == nums.size())
            return;

        int used[201] = {0};
        for(int i = startIndex; i < nums.size(); i++){
            if((sub.size() < 1 || nums[i] >= sub.back()) && used[nums[i]+100] != 1){
                used[nums[i]+100] = 1;
                sub.push_back(nums[i]);
                backtracking(nums, i+1, sub, result);
                sub.pop_back();
            }
            // if((!sub.empty() && nums[i] < sub.back()) || used[nums[i]+100] == 1)
            //     continue;
            // used[nums[i]+100] = 1;
            // sub.push_back(nums[i]);
            // backtracking(nums, i+1, sub, result);
            // sub.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;

        backtracking(nums, 0, sub, result);

        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}