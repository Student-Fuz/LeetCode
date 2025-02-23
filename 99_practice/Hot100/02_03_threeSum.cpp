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
// https://leetcode.cn/problems/3sum/description/?envType=study-plan-v2&envId=top-100-liked

// 
// j 从小到大
// k 从大到小
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> num_set;

        for(int i = 0; i < nums.size(); i++)
            num_set[nums[i]].push_back(i);

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

// Solution try1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        unordered_map<int, vector<int>> num_map;

        for(int i = 0; i < nums.size(); i++){
            num_map[nums[i]].push_back(i);
        }

        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int target = -(nums[i] + nums[j]);
                if(num_map.find(target) != num_map.end()){
                    for(const int& k : num_map[target]){
                        if(k > j){
                            result.push_back({nums[i], nums[j], nums[k]});
                            break;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}