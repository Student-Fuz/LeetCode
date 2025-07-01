#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) {
        // 最远可达
        int maxPos = 0;
        int step = 0;
        // 第step步的最远可达(含)
        int end = 0;

        for(int i = 0; i < nums.size()-1; i++){
            if(i <= maxPos){
                maxPos = max(maxPos, i + nums[i]);
                if(i == end){
                    end = maxPos;
                    step++;
                }
            }
        }

        return step;
        
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        // 最远可达
        int maxPos = 0;
        int step = 0;
        // 第step步的最远可达(含)
        int end = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i <= maxPos){
                maxPos = max(maxPos, i + nums[i]);
                if(i == end){
                    end = maxPos;
                    step++;
                    if(i == nums.size()-1){
                        step--;
                    }
                }
            }
        }

        return step;
        
    }
};

int main() {

    return 0;
}