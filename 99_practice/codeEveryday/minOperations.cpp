#include <bits/stdc++.h>
using namespace std;

// 要操作的次数
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(k > nums[0]) return -1;
        int cnt = 0;
        int maxNum = nums.back();
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < maxNum){
                maxNum = nums[i];
                cnt++;
            }
        }
        if(k != nums[0]) cnt++;
        return cnt;
    }
};

// 要操作的数的量
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(k > nums[0]) return -1;
        int cnt = 0;
        int n = 0;
        int maxNum = INT_MAX;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < maxNum){
                maxNum = nums[i];
                cnt += n;
                n++;
            }
            else if(nums[i] == maxNum){
                n++;
            }
        }
        if(k != nums[0]) cnt += maxNum;
        return cnt;
    }
};

int main() {

    return 0;
}