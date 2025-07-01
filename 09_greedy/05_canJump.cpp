#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i <= farthest){
                farthest = max(farthest, i+nums[i]);
                if(farthest >= nums.size()-1) return true;
            }
        }
        
        return false;
    }
};

int main() {

    return 0;
}