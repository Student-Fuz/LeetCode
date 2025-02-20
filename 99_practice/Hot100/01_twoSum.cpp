#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/two-sum/?envType=study-plan-v2&envId=top-100-liked

// 时间复杂度O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index_vec;

        // key--nums[index] val--index
        unordered_map<int, vector<int>> nums_map;

        for(int i = 0; i < nums.size(); i++){
            nums_map[nums[i]].push_back(i);
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums_map.find(target - nums[i]) != nums_map.end()){
                if(target - nums[i] == nums[i]){
                    if(nums_map[nums[i]].size() == 2){
                        index_vec = nums_map[nums[i]];
                        return index_vec;
                    } 
                }
                else{
                    index_vec.push_back(i);
                    index_vec.push_back(nums_map[target - nums[i]][0]);
                    return index_vec;
                }
            }
        }

        return index_vec;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}