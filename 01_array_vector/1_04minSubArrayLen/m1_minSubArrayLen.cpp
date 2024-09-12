#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// 暴力破解法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size(); 
        int len;
        int sum = 0;
        for(int i= 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum >= target){
            for(int i= 0; i < nums.size(); i++){
                sum = 0;
                len = 0;
                for(int j = i; j < nums.size(); j++){
                    len += 1;
                    sum += nums[j];
                    if(sum >= target)
                        break;
                }
                if(sum >= target){
                    if(len<minLen){
                        minLen = len;
                    }
                }
                // 此处开始的子数组和若小于目标，则不再遍历，以提升性能
                else
                    break;
            }
            return minLen;
        }
        // 不存在符合条件的子数组
        else{
            return 0;
        }

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