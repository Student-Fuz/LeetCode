#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // key--val, val--freq
        unordered_map<int, int> nums12;
        unordered_map<int, int> nums34;

        for(const auto& num1 : nums1){
            for(const auto& num2 : nums2){
                nums12[num1+num2]++;
            }
        }

        for(const auto& num3 : nums3){
            for(const auto& num4 : nums4){
                nums34[num3+num4]++;
            }
        }

        int result = 0;
        for(const auto& num34: nums34){
            int target = 0-num34.first;
            if(nums12.find(target) != nums12.end()){
                result += nums12[target] * num34.second;
            }
        }

        return result;
    }
};

int main() {

    return 0;
}