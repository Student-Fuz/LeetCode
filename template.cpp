#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
// m1： 合并两个区间再截取法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums1(nums);

        nums1.insert(nums.begin(), nums.begin(), nums.end());

        int x = nums.size() - k%nums.size();
        nums.assign(nums1.begin()+x, nums1.begin()+x+nums.size());
    }
};

// m2: 

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}