#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/description/?envType=daily-question&envId=2025-09-22

// 思路找到j结尾的所有数组，从0到n-1遍历j
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long r = 0, total = 0;
        for(int i = 0, j = 0; j < n; j++){
            total += nums[j];
            while(i <= j && total*(j-i+1) >= k){
                total -= nums[i];
                i++;
            }
            r += j-i+1;
        }
        return r;
    }
};

// 思路：找到长度为len的所有满足条件的窗口，从1到n遍历所有窗口长度
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long r = 0;
        long long sum = 0;
        long long begin = 0;
        int len = 1;
        for(; len <= nums.size(); len++){
            // 初始化
            sum = 0;
            for(int i = 0; i < len-1; i++){
                sum += nums[i];
            }
            for(int i = len-1; i < nums.size(); i++){
                sum += nums[i];
                if(sum*len < k) r++;
                sum -= nums[i-len+1];
            }
        }
        return r;
    }
};

// 标准答案
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};


int main() {

    return 0;
}