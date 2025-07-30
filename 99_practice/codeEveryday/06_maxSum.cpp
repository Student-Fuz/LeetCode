#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-unique-subarray-sum-after-deletion/?envType=daily-question&envId=2025-07-25

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> set;
        int sum = 0;
        for(auto num : nums){
            if(num > 0 && set.find(num) == set.end()){
                sum += num;
                set.insert(num);
            }
        }
        if(set.empty()){
            sum = INT_MIN;
            for(auto num : nums){
                sum = max(sum, num);
            }
        }
        return sum;
    }
};

int main() {

    return 0;
}