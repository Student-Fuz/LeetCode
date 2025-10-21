#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if(nums.size() <= 2) return 0;
        int cnt = 0;
        for(int i = 0, j = 1, k = 2; k < nums.size(); i++, j++, k++){
            if((nums[i]+nums[k])*2 == nums[j]) cnt++;
        }
        return cnt;
    }
};

int main() {

    return 0;
}