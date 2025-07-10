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
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightmost = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i <= rightmost){
                rightmost = max(rightmost, i+nums[i]);
                if(rightmost >= nums.size()-1) return true;
            }
        }

        return false;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}