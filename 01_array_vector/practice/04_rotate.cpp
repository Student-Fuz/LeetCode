#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        nums.insert(nums.end(), nums.begin(), nums.end());
        nums.assign(nums.begin()+len-k, nums.begin()+2*len-k);
    }
};

int main(){

    Solution s;

    return 0;
}