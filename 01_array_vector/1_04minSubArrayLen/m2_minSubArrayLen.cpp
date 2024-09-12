#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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


int main(){ 
    Solution s;
    vector v = {0,1,2,2,3,0,4,2};
    int result = s.minSubArrayLen(7, v);
    cout << result << endl;
    return 0;
}