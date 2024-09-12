#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 滑动窗口法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size(); 
        int sum = 0;
        // start = 0 end = 0
        // 滑动窗口[start,end)，长度为end-start
        int end;
        for(end = 0; end < nums.size(); end++){
            // 不存在符合条件的子数组
            if(sum >= target)
                break;
            sum += nums[end];
        }
        if(sum < target)
            return 0;
        minLen = end;
        // 前移start，从1开始
        for(int start = 1; start < nums.size(); start++){
            sum -= nums[start-1];
            for(; end < nums.size(); end++){
                if(sum >= target)
                    break;
                sum += nums[end];
            }
            if(sum >= target){
                if(end - start < minLen)
                    minLen = end - start;
            }
        }
        return minLen;
    }
};



int main(){ 
    Solution s;
    vector v = {0,1,2,2,3,0,4,2};
    int result = s.minSubArrayLen(7, v);
    // 正确结果--3，最长子数组长度为3
    cout << result << endl;
    return 0;
}