#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int cnt = 0;
        long long res = 0;
        int target = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            target = max(target, nums[i]);
        }
        // init
        int i = 0, j = 0;
        for(; j < nums.size(); j++){
            if(nums[j] == target) cnt++;
            if(cnt == k) break;
        }
        if(cnt < k) return 0;
        for(; i < nums.size(); i++){
            if(nums[i] == target) break;
        }
        res += i+1;
        j++;
        for(; j < nums.size(); j++){
            if(nums[j] == target){
                i++;
                while(i <= j){
                    if(nums[i] == target) break;
                    i++;
                }
            }
            res += i+1;
        }
        return res;
    }
};

int main() {

    return 0;
}