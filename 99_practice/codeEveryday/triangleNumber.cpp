#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;

        for (int l = 0; l < n - 2; l++) {
            if(nums[l] == 0) continue;
            int r = l + 2; // r 每次从 l+2 开始
            for (int m = l + 1; m < n - 1; m++) {
                while (r < n && nums[l] + nums[m] > nums[r]) {
                    r++;
                }
                // 此时 r 是第一个不满足的位置
                res += (r - m - 1);
            }
        }
        return res;
    }
};


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        int l = 0, m = 1, r = 2;
        for(; l < nums.size()-2; l++){
            for(m = l + 1; m < nums.size()-1; m++){
                for(; r < nums.size(); r++){
                    if(nums[r] >= nums[l] + nums[m]){
                        r--;
                        break;
                    }
                }
                if(r == nums.size()) r--;
                if(r != m){
                    res += r - m;
                }
                else{
                    r += 2;
                }
                // r = r == m ? (r+1) : r;
            }
        }
        return res;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        int l = 0, m = 1, r = 2;
        for(; l < nums.size()-2; l++){
            for(m = l + 1; m < nums.size()-1; m++){
                for(; r < nums.size(); r++){
                    // 错误：有可能所有的r都满足条件，导致没有统计
                    // if(nums[r] >= nums[l] + nums[m]){
                    //     res += r - m - 1;
                    //     break;
                    // }
                    if(nums[r] < nums[l] + nums[m]){
                        res += 1;
                        // break;
                    }
                    else{
                        break;
                    }
                }

            }
        }
        return res;
    }
};

int main() {

    vector<int> nums = {2,2,3,4};



    return 0;
}