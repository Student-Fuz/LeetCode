#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/taking-maximum-energy-from-the-mystic-dungeon/submissions/669236190/?envType=daily-question&envId=2025-10-10

// 暴力
// 时间复杂度 O(n*n/k)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxEnergy = INT_MIN;
        for(int i = 0; i < energy.size(); i++){
            int tmp = 0;
            for(int j = i; j < energy.size(); j+=k){
                tmp += energy[j];
            }
            maxEnergy = max(maxEnergy, tmp);
        }
        return maxEnergy;
    }
};

// 时间复杂度 O(kn)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxEnergy = INT_MIN;
        int n = energy.size();
        for(int i = n-k; i <= n-1; i++){
            int sum = 0;
            for(int j = i; j >= 0; j-=k){
                sum += energy[j];
                maxEnergy = max(maxEnergy, sum);
            }
        }
        return maxEnergy;
    }
};

int main() {

    return 0;
}