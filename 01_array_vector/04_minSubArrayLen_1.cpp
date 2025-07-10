#include <bits/stdc++.h>

using namespace std;

// 滑动窗口法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int start = -1;
        int end = 0;
        int minLen = INT_MAX;

        for(int start = 0; start < nums.size(); start++){
            while(end != nums.size() && sum < target){
                sum += nums[end];
                end++;
            }
            if(end == nums.size()){
                if(sum < target)
                    break;
            }
            minLen = min(end - start, minLen);
            sum -= nums[start];
        }

        return minLen == INT_MAX? 0 : minLen;

    }
};




int main(){ 

    return 0;
}