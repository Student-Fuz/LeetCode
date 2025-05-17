#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/3sum/description/

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         if(nums.size() < 3)
//             return {};
//         unordered_map<int, vector<vector<int>>> twoSum;

//         vector<vector<int>> result;
//         for(int i = 1; i < nums.size(); i++){
//             if(twoSum.find(0-nums[i]) != twoSum.end()){
//                 for(int k = 0; k < twoSum[0-nums[i]].size(); i++){
//                     result.push_back(twoSum[0-nums[i]][k]);
//                     result.back().push_back(nums[i]);
//                 }
//             }
//             for(int j = 0; j < i; j++){
//                 twoSum[nums[i] + nums[j]].push_back({nums[i], nums[j]});
//             }
//         }

//         return result;
//     }
// };

// 排序以防重复
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};
        unordered_map<int, vector<vector<int>>> twoSum;

        vector<vector<int>> result;
        for(int i = 1; i < nums.size(); i++){
            // 找该数 对应的 前两数之和
            if(twoSum.find(0-nums[i]) != twoSum.end()){
                for(int k = 0; k < twoSum[0-nums[i]].size(); i++){
                    result.push_back(twoSum[0-nums[i]][k]);
                    result.back().push_back(nums[i]);
                }
            }
            // 前两数之和
            for(int j = 0; j < i; j++){
                twoSum[nums[i] + nums[j]].push_back({nums[i], nums[j]});
            }
        }

        return result;
    }
};


// 标准答案
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> num_set;

        for(int i = 0; i < nums.size(); i++)
            num_set[nums[i]].push_back(i);

        // 防止重复
        // i == 0 || nums[i] !=  nums[i-1]
        // j == i+1 || nums[j] != nums[j-1]
        // k == j+1 || nums[k] != nums[k-1]

        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] !=  nums[i-1]){
                for(int j = i+1; j < nums.size(); j++){
                    if(j == i+1 || nums[j] != nums[j-1]){
                        int target = -(nums[i] + nums[j]);
                        if(num_set.find(target) != num_set.end()){
                            for(const int& k : num_set[target]){
                                if(k > j){
                                    if(k == j+1 || nums[k] != nums[k-1]){
                                        result.push_back({nums[i], nums[j], nums[k]});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {

    return 0;
}