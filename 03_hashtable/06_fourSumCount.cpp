#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

// 示例 1：

// 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// 输出：2
// 解释：
// 两个元组如下：
// 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
// 示例 2：

// 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
// 输出：1
 

//   提示：

// n == nums1.length
// n == nums2.length
// n == nums3.length
// n == nums4.length
// 1 <= n <= 200
// -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

// 自己第一遍写的
// 特点：集合递减
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int, int> sum_s1_s2;
        std::unordered_map<int, int> sum_s3_s4;
        int sum = 0;

        // get sum_s1_s2
        for(auto num1 : nums1){
            for(auto num2 : nums2){
                int sum1 = num1 + num2;
                if(sum_s1_s2.find(sum1) != sum_s1_s2.end())
                    sum_s1_s2[sum1] += 1;
                else
                    sum_s1_s2.insert({sum1, 1});
            }
        }

        // get sum_s3_s4
        for(auto num3 : nums3){
            for(auto num4 : nums4){
                int sum2 = num3 + num4;
                if(sum_s3_s4.find(sum2) != sum_s3_s4.end())
                    sum_s3_s4[sum2] += 1;
                else
                    sum_s3_s4.insert({sum2, 1});
            }
        }

        for(auto it1 = sum_s1_s2.begin(); it1 != sum_s1_s2.end(); it1++){
            auto it2 = sum_s3_s4.find(0 - it1->first);
            if(it2 != sum_s3_s4.end())
                sum = sum + it1->second * it2->second;
        }

        return sum;
    }
};


int main(){

    Solution s;
    // cout << s.twoSUm(19);
    return 0;
}

