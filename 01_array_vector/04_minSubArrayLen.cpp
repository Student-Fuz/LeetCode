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

// 二分查找法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size(); 
        int len = 0;
        int sum = 0;
        vector<int> sums(nums.size());
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            sums[i] = sum;
        }
        // 所有值之和都小于目标值
        // 即无最小子序列
        if(sums[nums.size()-1] < target)
            return 0;
        // sums[j] - sums[i] ---> nums[i+1]到nums[j]的元素和
        // 二分查找元素 sum[j] >= sums[i] + target
        for(int i = 0; i < nums.size()-1; i++){
            auto it = std::lower_bound(sums.begin()+i, sums.end(), sums[i] + target);
            len = std::distance(sums.begin()+i, it);
            // 找到了子序列
            if(it != sums.end()){
                if(len < minLen){
                    minLen = len;
                }
            }
        }
        return minLen;
    }
};

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
    vector<int> v = {0,1,2,2,3,0,4,2};
    int result = s.minSubArrayLen(7, v);
    // 正确结果--3，最长子数组长度为3
    cout << result << endl;
    return 0;
}