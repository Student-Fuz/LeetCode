#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/next-permutation/description/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int i, j, k;
        k = nums.size() - 1;
        for(i = nums.size()-2; i >= 0; i--){
            if(nums[i+1] > nums[i])
                break;
        }
        j = i+1;

        if(i >= 0){
            while(nums[i] >= nums[k])
                k--;
            swap(nums[i], nums[k]);
        }

        // 翻转[j : end)
        for(int l = j, m = nums.size()-1; l < m; l++, m--){
            swap(nums[l], nums[m]);
        }
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}