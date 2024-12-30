#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述


// Solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 1; i < nums.size(); i++)
            result ^= nums[i];
        return result;
    }
};

int main(){

    Solution s;

    return 0;
}