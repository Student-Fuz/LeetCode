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
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        int lower = distance(nums.begin(), it);

        it = upper_bound(nums.begin(), nums.end(), target);
        int upper = distance(nums.begin(), it);

        if(lower == nums.size() || nums[lower] != target)
            return {-1, -1};
        
        return {lower, upper-1};
    }
};

int main(){

    cout << "Hello, world!" << endl;

    return 0;
}