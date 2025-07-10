#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/3sum/submissions/601889946/

// 返回值--双指针
// 返回索引--哈希表
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> numMap;

        for(int i = 0; i < nums.size(); i++){
            numMap[nums[i]].push_back(i);
        }

        vector<vector<int>> result;

        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] != nums[i-1]){
                for(int j = i+1; j < nums.size(); j++){
                    if(j == i+1 || nums[j] != nums[j-1]){
                        int target = 0 - nums[i] - nums[j];
                        if(numMap.find(target) != numMap.end()){
                            for(const auto& k : numMap[target]){
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