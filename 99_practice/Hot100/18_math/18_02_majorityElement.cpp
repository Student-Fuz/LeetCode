#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/majority-element/submissions/585034404/?envType=study-plan-v2&envId=top-100-liked

// Boyer-Moore 投票算法 时间最优、空间最优
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = 0;
        int cnt = 0;
        for(auto& num : nums){
            if(cnt == 0){
                can = num;
                cnt++;
                continue;
            }
            if(num == can){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return can;
    }
};

int main() {

    return 0;
}
