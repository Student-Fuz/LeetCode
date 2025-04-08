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
// 思路：左累积数组、右累积数组
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l(nums.size());
        vector<int> r(nums.size());

        l[0] = 1;
        r[nums.size()-1] = 1;

        for(int i = 1; i < nums.size(); i++){
            l[i] = l[i-1] * nums[i-1];
        }

        for(int i = nums.size()-2; i >= 0; i--){
            r[i] = r[i+1] * nums[i+1];
        }

        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++){
            res[i] = l[i] * r[i];
        }

        return res;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}