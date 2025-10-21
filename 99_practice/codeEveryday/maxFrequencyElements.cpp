#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2025-09-22

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto& num : nums){
            map[num]++;
        }
        int maxF = 0;
        int times = 0;
        for(auto& [num, frq] : map){
            if(frq > maxF){
                maxF = frq;
                times = frq;
            }
            else if(frq == maxF){
                times += frq;
            }
        }
        return times;
    }
};

int main() {

    return 0;
}