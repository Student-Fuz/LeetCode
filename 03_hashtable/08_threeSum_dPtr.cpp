#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。


// 示例 1：

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。
// 示例 2：

// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。
// 示例 3：

// 输入：nums = [0,0,0]
// 输出：[[0,0,0]]
// 解释：唯一可能的三元组和为 0 。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::unordered_map<int, vector<vector<int>>> sum_n1_n2;
        vector<vector<int>> result_vec;

        for(int i = 1; i < nums.size();){
            for(int j = i-1; j > 0; j--){
                if(sum_n1_n2.find(nums[i] + nums[j]) != sum_n1_n2.end())
                    sum_n1_n2[nums[i] + nums[j]].push_back({nums[j], nums[i]});
                else    
                    sum_n1_n2.insert({nums[i] + nums[j], {{nums[j], nums[i]}}});
            }
            i++;
            if(sum_n1_n2.find(0-nums[i]) != sum_n1_n2.end())
                result_vec.push_back();
        }
        return result_vec;
    }

    
};


int main(){

    Solution s;
    // cout << s.twoSum(19);
    return 0;
}

