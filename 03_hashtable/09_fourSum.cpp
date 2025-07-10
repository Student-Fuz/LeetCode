#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/4sum/description/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> numMap;

        for(int i = 0; i < nums.size(); i++){
            numMap[nums[i]].push_back(i);
        }

        vector<vector<int>> result;
        // 非负数组剪枝 TODO
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] != nums[i-1]){
                for(int j = i+1; j < nums.size(); j++){
                    if(j == i+1 || nums[j] != nums[j-1]){
                        for(int k = j+1; k < nums.size(); k++){
                            if(k == j+1 || nums[k] != nums[k-1]){
                                long last = long(target) - long(nums[i]) - long(nums[j]) - long(nums[k]);
                                if(last > INT_MAX || last < INT_MIN)
                                    continue;
                                if(numMap.find(last) != numMap.end()){
                                    for(const auto& l : numMap[last]){
                                        if(l > k){
                                            if(l == k+1 || nums[l] != nums[l-1]){
                                                result.push_back({nums[i], nums[j], nums[k], nums[l]});
                                            }
                                        }
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