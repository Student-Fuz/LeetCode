#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/number-of-zero-filled-subarrays/?envType=daily-question&envId=2025-08-21

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        long long cnt = 0;
        for(; r < nums.size(); r++){
            if(l == r){
                if(nums[r] != 0){
                    l++;
                }
            }
            else{
                if(nums[r] != 0){
                    int lenSub = r - l;
                    cnt += (long long)(1+lenSub)*lenSub/2;
                    l = r+1;
                }
            }
        }
        int lenSub = r - l;
        cnt += (long long)(1 + lenSub) * lenSub / 2;
        return cnt;
    }
};

// 更优
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, cur = 0;
        for (int x : nums) {
            if (x == 0) {
                cur++;        // 当前连续 0 的长度
                cnt += cur;   // 每个位置结尾的子数组个数
            } else {
                cur = 0;
            }
        }
        return cnt;
    }
};


int main() {

    return 0;
}