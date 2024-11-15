#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

// 你可以按任意顺序返回答案。

 

// 示例 1：

// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 示例 2：

// 输入：nums = [3,2,4], target = 6
// 输出：[1,2]
// 示例 3：

// 输入：nums = [3,3], target = 6
// 输出：[0,1]

// 自己第一遍写的
// 特点：集合递减
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // std::unordered_set<int> candidate_set = {};
        std::multiset<int> candidate_set = {};
        std::vector<int> index_vec = {};
        candidate_set.insert(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; ++i){
            auto it = candidate_set.find(nums[i]);
            if (it != candidate_set.end()) {
                candidate_set.erase(it); 
            }
            if(candidate_set.find(target - nums[i]) != candidate_set.end()){
                index_vec.push_back(i);
                for(int j = i+1; j < nums.size(); ++j){
                    if(nums[j] == target - nums[i]){
                        index_vec.push_back(j);
                        break;
                    }
                }
                break;
            }
        }
        return index_vec;
    }
};

// 标准答案 
// 特点：集合递增
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hash;
        for(int i = 0;i < nums.size();i++){
            if(hash.find(target - nums[i]) != hash.end()){
                return {hash[ target - nums[i] ], i};
            }
            hash[ nums[i] ] = i;
        }
        return {};
    }
};

int main(){

    Solution s;
    // cout << s.twoSUm(19);
    return 0;
}