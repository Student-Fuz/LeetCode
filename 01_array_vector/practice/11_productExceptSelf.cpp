#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L;
        vector<int> R;

        L.resize(nums.size());
        R.resize(nums.size());

        vector<int> result;

        int productLeft = 1;
        int productRight = 1;
        for(int i = 0; i < nums.size()-1; i++){
            L[i] = (productLeft);
            productLeft = productLeft * nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
            R[i] = productRight;
            productRight = productRight * nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            result.push_back(L[i] * R[i]);
        }

        return result;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L;
        vector<int> R;
        vector<int> result;

        L.resize(nums.size());
        R.resize(nums.size());
        result.resize(nums.size());
    
        int productLeft = 1;
        int productRight = 1;
        for(int i = 0; i < nums.size(); i++){
            L[i] = (productLeft);
            productLeft = productLeft * nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
            result[i] = L[i] * productRight;
            productRight = productRight * nums[i];
        }

        return result;
    }
};

int main(){

    Solution s;

    return 0;
}